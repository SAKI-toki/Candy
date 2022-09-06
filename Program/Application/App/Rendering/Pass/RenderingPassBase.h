/*****************************************************************//**
 * \file   RenderingPassBase.h
 * \brief  レンダリングパスの基底
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_RENDERING_PASS_BASE_H
#define CANDY_APP_RENDERING_PASS_BASE_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	class PassBase
	{
	public:
		virtual ~PassBase() = default;

		virtual void startup() {}
		virtual void cleanup() {}

		virtual void beginPass(graphic::CommandList& /*_commandList*/) {}
		virtual void endPass(graphic::CommandList& /*_commandList*/) {}
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_RENDERING_PASS_BASE_H
