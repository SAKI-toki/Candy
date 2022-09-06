/*****************************************************************//**
 * \file   RenderingManager.h
 * \brief  レンダリングの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_RENDERING_MANAGER_H
#define CANDY_APP_RENDERING_MANAGER_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	void Startup();
	void Cleanup();

	void PreDraw();
	void PostDraw();

	graphic::CommandList& GetModelCommandList();
	graphic::CommandList& GetSpriteCommandList();
#if BUILD_DEBUG
	graphic::CommandList& GetDebug2DCommandList();
#endif // BUILD_DEBUG
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_RENDERING_MANAGER_H
