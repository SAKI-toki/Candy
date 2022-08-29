/*****************************************************************//**
 * \file   ComponentManager.cpp
 * \brief  コンポーネント管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentManager.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace Manager
	{
		void ComponentUpdate(void(Base::* _baseFunc)())
		{
			if (!_baseFunc)return;
			for (auto& componentList : m_ComponentLists)
			{ 
				for (auto& component : componentList)
				{
					if (!component)continue;
					(component->*_baseFunc)();
				}
			}
		}
	}

	void Manager::Startup()
	{
		m_ComponentLists.resize(Priority::GetCount());
	}

	void Manager::Cleanup()
	{
		m_ComponentLists.clear();
	}

	void Manager::PreUpdate()
	{
		ComponentUpdate(&Base::preUpdate);
	}

	void Manager::Update()
	{
		ComponentUpdate(&Base::update);
	}

	void Manager::PostUpdate()
	{
		ComponentUpdate(&Base::postUpdate);
	}

	void Manager::removeComponent(const Base* const _component)
	{
		if (!_component)return;
		
		const s32 prio = Priority::GetFromId(_component->getClassId());
		auto& componentList = m_ComponentLists[prio];

		for (s32 i = 0; i < (s32)componentList.size(); ++i)
		{
			if (_component != componentList[i])continue;
			delete componentList[i];
			componentList.erase(componentList.begin() + i);
			return;
		}
	}
}

CANDY_APP_NAMESPACE_END
