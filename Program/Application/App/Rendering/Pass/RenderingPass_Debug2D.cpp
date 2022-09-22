/*****************************************************************//**
 * \file   RenderingPass_Debug2D.cpp
 * \brief  2Dデバッグレンダリングパス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#if BUILD_DEBUG

#include "RenderingPass_Debug2D.h"
#include <App/Rendering/RenderingParam.h>

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	void Debug2DPass::beginPass(graphic::CommandList& _commandList)
	{
		_commandList.setRenderTargetsDepthStencil(m_RenderTargetBufferDescriptor.getCpuHandle(0), 1, m_DepthStencilBufferDescriptor.getCpuHandle(0));
		_commandList.setViewport(m_Viewport);
		_commandList.setScissorRect(m_ScissorRect);
	}
}

CANDY_APP_NAMESPACE_END

#endif // BUILD_DEBUG
