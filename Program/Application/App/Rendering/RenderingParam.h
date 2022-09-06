/*****************************************************************//**
 * \file   RenderingParam.h
 * \brief  レンダリング関連の変数
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_RENDERING_PARAM_H
#define CANDY_APP_RENDERING_PARAM_H

#include <App/AppInclude.h>
#include "Pass/RenderingPassBase.h"

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	inline graphic::Viewport m_Viewport;
	inline graphic::ScissorRect m_ScissorRect;
	inline graphic::Buffer m_RenderTargetBuffer;
	inline graphic::Descriptor m_RenderTargetBufferDescriptor;
	inline graphic::Buffer m_DepthStencilBuffer;
	inline graphic::Descriptor m_DepthStencilBufferDescriptor;

	inline std::vector<std::pair<std::unique_ptr<PassBase>, graphic::CommandList>> m_PassCommandListPairs;

	enum class PASS_TYPE
	{
		BEGIN_FRAME,
		MODEL,
		SPRITE,
#if BUILD_DEBUG
		DEBUG2D,
#endif // BUILD_DEBUG
		END_FRAME,

		SIZE,
	};
	inline std::array<graphic::CommandList, (s32)PASS_TYPE::SIZE> m_CommandLists;
	inline graphic::CommandList& GetCommandList(const PASS_TYPE _type) { return m_CommandLists[(s32)_type]; }
	
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_RENDERING_PARAM_H
