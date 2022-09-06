/*****************************************************************//**
 * \file   RenderingPass_BeginFrame.cpp
 * \brief  フレーム開始レンダリングパス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "RenderingPass_BeginFrame.h"

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	void BeginFramePass::beginPass(graphic::CommandList& _commandList)
	{
		auto renderTargetBufferDescriptorCpuHandle = m_RenderTargetBufferDescriptor.getCpuHandle(0);
		auto depthStencilBufferDescriptorCpuHandle = m_DepthStencilBufferDescriptor.getCpuHandle(0);
		_commandList.translationBufferBarrier(m_RenderTargetBuffer, graphic::types::BARRIER_STATE::PIXEL_SHADER_RESOURCE, graphic::types::BARRIER_STATE::RENDER_TARGET);
		_commandList.setRenderTargetsDepthStencil(renderTargetBufferDescriptorCpuHandle, 1, depthStencilBufferDescriptorCpuHandle);
		_commandList.setViewport(m_Viewport);
		_commandList.setScissorRect(m_ScissorRect);
		_commandList.clearRenderTarget(renderTargetBufferDescriptorCpuHandle, core::GetColorRGB32(0x20, 0x20, 0x20));
		_commandList.clearDepthStencil(depthStencilBufferDescriptorCpuHandle, 1.0f, 0);
	}
}

CANDY_APP_NAMESPACE_END
