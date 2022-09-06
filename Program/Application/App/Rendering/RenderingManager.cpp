/*****************************************************************//**
 * \file   RenderingManager.cpp
 * \brief  レンダリングの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "RenderingManager.h"
#include "RenderingParam.h"
#include "Pass/RenderingPass_BeginFrame.h"
#include "Pass/RenderingPass_Debug2D.h"
#include "Pass/RenderingPass_EndFrame.h"
#include "Pass/RenderingPass_Model.h"
#include "Pass/RenderingPass_Sprite.h"

CANDY_APP_NAMESPACE_BEGIN

void RenderingManager::Startup()
{
	auto& graphicDevice = graphic::System::GetDevice();

	for (auto& commandList : m_CommandLists)
	{
		commandList.startup(graphicDevice, graphic::types::COMMAND_LIST_TYPE::RENDERING, graphic::Config::GetBackBufferCount());
		commandList.close();
	}

	Rect screenRect{ 0.0f, 0.0f, static_cast<f32>(graphic::Config::GetScreenWidth()), static_cast<f32>(graphic::Config::GetScreenHeight()) };
	m_Viewport.set(screenRect, 0.0f, 1.0f);
	m_ScissorRect.set(screenRect);

	graphic::BufferStartupInfo renderTargetBufferStartupInfo;
	renderTargetBufferStartupInfo.setRenderTargetStartupInfo(graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM,
		graphic::Config::GetScreenWidth(), graphic::Config::GetScreenHeight(), core::GetColorRGB32(0x20, 0x20, 0x20));
	renderTargetBufferStartupInfo.setInitBarrierState(graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE);
	m_RenderTargetBuffer.startup(graphicDevice, renderTargetBufferStartupInfo);
	m_RenderTargetBufferDescriptor.startup(graphicDevice, graphic::types::DESCRIPTOR_TYPE::RENDER_TARGET, 1);
	m_RenderTargetBufferDescriptor.bindingRenderTarget(graphicDevice, 0, m_RenderTargetBuffer, graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM);
	m_RenderTargetBuffer.setName("m_RenderTargetBuffer");

	graphic::BufferStartupInfo depthStencilBufferStartupInfo;
	depthStencilBufferStartupInfo.setDepthStencilStartupInfo(graphic::types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT,
		graphic::Config::GetScreenWidth(), graphic::Config::GetScreenHeight());
	m_DepthStencilBuffer.startup(graphicDevice, depthStencilBufferStartupInfo);
	m_DepthStencilBufferDescriptor.startup(graphicDevice, graphic::types::DESCRIPTOR_TYPE::DEPTH_STENCIL, 1);
	m_DepthStencilBufferDescriptor.bindingDepthStencil(graphicDevice, 0, m_DepthStencilBuffer, graphic::types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT);

	m_PassCommandListPairs.push_back({ std::make_unique<BeginFramePass>(), GetCommandList(PASS_TYPE::BEGIN_FRAME) });
	m_PassCommandListPairs.push_back({ std::make_unique<ModelPass>(), GetCommandList(PASS_TYPE::MODEL) });
	m_PassCommandListPairs.push_back({ std::make_unique<SpritePass>(), GetCommandList(PASS_TYPE::SPRITE) });
#if BUILD_DEBUG
	m_PassCommandListPairs.push_back({ std::make_unique<Debug2DPass>(), GetCommandList(PASS_TYPE::DEBUG2D) });
#endif // BUILD_DEBUG
	m_PassCommandListPairs.push_back({ std::make_unique<EndFramePass>(), GetCommandList(PASS_TYPE::END_FRAME) });

	for (s32 i = 0; i < (s32)PASS_TYPE::SIZE; ++i)
	{
		const auto passType = (PASS_TYPE)i;
		GetCommandList(passType).setName(nameof::nameof_enum(passType));
	}

	for (auto& [pass, commandList] : m_PassCommandListPairs)if (pass)pass->startup();
}

void RenderingManager::Cleanup()
{
	m_DepthStencilBufferDescriptor.cleanup();
	m_DepthStencilBuffer.cleanup();
	for (auto& [pass, commandList] : m_PassCommandListPairs)if (pass)pass->cleanup();
	m_PassCommandListPairs.clear();
	for (auto& commandList : m_CommandLists)commandList.cleanup();
}

void RenderingManager::PreDraw()
{
	for (auto& commandList : m_CommandLists)commandList.preDraw(graphic::System::GetBackBufferIndex());

	for (auto& [pass, commandList] : m_PassCommandListPairs)
	{
		if (pass)pass->beginPass(commandList);
	}

	graphic::ResourceManager::Regist(m_DepthStencilBuffer);
	graphic::ResourceManager::Regist(m_DepthStencilBufferDescriptor);
}

void RenderingManager::PostDraw()
{
	for (auto& [pass, commandList] : m_PassCommandListPairs)
	{
		if (!pass)pass->endPass(commandList);
	}

	for (auto& commandList : m_CommandLists)
	{
		commandList.close();
		graphic::System::ExecuteCommandList(commandList);
	}
}

graphic::CommandList& RenderingManager::GetModelCommandList()
{
	return GetCommandList(PASS_TYPE::MODEL);
}

graphic::CommandList& RenderingManager::GetSpriteCommandList()
{
	return GetCommandList(PASS_TYPE::SPRITE);
}

#if BUILD_DEBUG
graphic::CommandList& RenderingManager::GetDebug2DCommandList()
{
	return GetCommandList(PASS_TYPE::DEBUG2D);
}
#endif // BUILD_DEBUG

CANDY_APP_NAMESPACE_END
