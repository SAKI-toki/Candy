/*****************************************************************//**
 * \file   RenderingPass_BeginFrame.h
 * \brief  フレーム開始レンダリングパス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_RENDERING_PASS_BEGIN_FRAME_H
#define CANDY_APP_RENDERING_PASS_BEGIN_FRAME_H

#include <App/AppInclude.h>
#include "RenderingPassBase.h"

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	class BeginFramePass : public PassBase
	{
	public:
		void beginPass(graphic::CommandList& _commandList)override;
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_RENDERING_PASS_BEGIN_FRAME_H
