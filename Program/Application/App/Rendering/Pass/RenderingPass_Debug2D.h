/*****************************************************************//**
 * \file   RenderingPass_Debug2D.h
 * \brief  2Dデバッグレンダリングパス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_RENDERING_PASS_DEBUG_2D_H
#define CANDY_APP_RENDERING_PASS_DEBUG_2D_H

#if BUILD_DEBUG

#include <App/AppInclude.h>
#include "RenderingPassBase.h"

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	class Debug2DPass : public PassBase
	{
	public:
		void beginPass(graphic::CommandList& _commandList)override;
	};
}

CANDY_APP_NAMESPACE_END

#endif // BUILD_DEBUG

#endif // CANDY_APP_RENDERING_PASS_DEBUG_2D_H
