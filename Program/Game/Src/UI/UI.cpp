#include "UI.h"
#include <Graphic/Graphic.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/Buffer/GraphicBuffer.h>

CANDY_NAMESPACE_BEGIN

namespace UI
{
	std::vector<Graphic::Buffer> m_RenderTargetBuffers;
	std::vector<Graphic::Buffer> m_MaskStencilBuffers;
}

void UI::Startup()
{
	auto& device = Graphic::GetDevice();

	Graphic::BufferStartupInfo bufferStartupInfo;
	bufferStartupInfo.setRenderTargetStartupInfo(Graphic::GRAPHIC_FORMAT::R8G8B8A8_UNORM,
		Graphic::GetScreenWidth(), Graphic::GetScreenHeight());
	m_RenderTargetBuffers.resize(Graphic::GetBackBufferCount());
	for (auto& renderTargetBuffer : m_RenderTargetBuffers)renderTargetBuffer.startup(device, bufferStartupInfo);

	bufferStartupInfo.setDepthStencilStartupInfo(Graphic::GRAPHIC_FORMAT::D24_UNORM_S8_UINT,
		Graphic::GetScreenWidth(), Graphic::GetScreenHeight());
	m_MaskStencilBuffers.resize(Graphic::GetBackBufferCount());
	for (auto& maskStencilBuffer : m_MaskStencilBuffers)maskStencilBuffer.startup(device, bufferStartupInfo);
}

void UI::Cleanup()
{

}

void UI::Update()
{

}

void UI::Draw()
{
	//auto& commandList = Graphic::GetCommandList();
	//commandList.setRenderTargetsDepthStencil();
}

CANDY_NAMESPACE_END
