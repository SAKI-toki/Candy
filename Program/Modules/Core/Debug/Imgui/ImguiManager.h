/*****************************************************************//**
 * \file   ImguiManager.h
 * \brief  Imguiの管理
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_DEBUG_IMGUI_MANAGER_H
#define CANDY_CORE_DEBUG_IMGUI_MANAGER_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Debug
{
	namespace ImguiManager
	{
		void Startup();
		void Cleanup();

		void BeginFrame();
		void EndFrame();
	}
}


CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_DEBUG_IMGUI_MANAGER_H
