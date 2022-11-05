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

class Entity;

class ComponentBase;

namespace ComponentManager
{
	void Startup();
	void Cleanup();

	void PreUpdate();
	void Update();
	void PostUpdate();

	void PreRender();
	void Render();
	void PostRender();

	template<typename T, typename ...ArgsT, IsBaseComponentComponentInterfaceT<T> = nullptr>
	std::weak_ptr<ComponentBase> addComponent(const std::weak_ptr<Entity>& _ownerEntity, ArgsT&& ..._args);

	void removeComponent(const std::weak_ptr<ComponentBase>& _component);
};

CANDY_APP_NAMESPACE_END

#include "ComponentManager.inl"

#endif // CANDY_APP_COMPONENT_MANAGER_H
