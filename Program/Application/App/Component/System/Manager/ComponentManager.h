/*****************************************************************//**
 * \file   ComponentManager.h
 * \brief  コンポーネント管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_MANAGER_H
#define CANDY_APP_COMPONENT_MANAGER_H

#include <App/AppInclude.h>
#include <App/Component/ComponentDef.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class Base;

	namespace Manager
	{
		void Startup();
		void Cleanup();

		void PreUpdate();
		void Update();
		void PostUpdate();

		template<typename T, typename ...ArgsT, is_base_component_interface_t<T> = nullptr>
		Base* addComponent(const EntityHandle _ownerHandle, ArgsT&& ..._args);

		void removeComponent(const Base* const _component);
	};
}

CANDY_APP_NAMESPACE_END

#include "ComponentManager.inl"

#endif // CANDY_APP_COMPONENT_MANAGER_H
