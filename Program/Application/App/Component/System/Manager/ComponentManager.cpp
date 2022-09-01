/*****************************************************************//**
 * \file   ComponentManager.cpp
 * \brief  コンポーネント管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentManager.h"
#include <App/Component/ComponentBase.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace Manager
	{
		core::JobSystem m_JobSystem;

		void TransformComponentImpl(void(Base::* _baseFunc)(), std::vector<Base*>& _componentList, std::atomic<int>& _index)
		{
			while (true)
			{
				const s32 localIndex = _index++;
				if (localIndex >= (s32)_componentList.size())break;

				auto& component = _componentList[localIndex];
				if (!component)continue;

				(component->*_baseFunc)();
			}
		}

		void TransformComponent(void(Base::* _baseFunc)(), std::vector<std::vector<Base*>>& _componentLists)
		{
			if (!_baseFunc)return;
			
			std::atomic<s32> index = 0;

			for (s32 i = 0; i < (s32)_componentLists.size(); ++i)
			{
				auto& componentList = _componentLists[i];

				index = 0;
				m_JobSystem.reset();
				m_JobSystem.setFunction(
					[&_baseFunc, &componentList, &index]() { TransformComponentImpl(_baseFunc, componentList, index); },
					m_JobSystem.getThreadCount());

				m_JobSystem.execute();
				m_JobSystem.wait();
			}
		}
	}

	void Manager::Startup()
	{
		m_UpdateComponentLists.resize(PriorityTable::GetUpdatePriorityCount());
		m_RenderComponentLists.resize(PriorityTable::GetRenderPriorityCount());
		s32 coreNoList[] = { 0, 2, 3, 4 };
		m_JobSystem.startup(coreNoList, core::GetArraySize(coreNoList));
	}

	void Manager::Cleanup()
	{
		m_JobSystem.cleanup();
		m_UpdateComponentLists.clear();
		m_RenderComponentLists.clear();
	}

	void Manager::PreUpdate()
	{
		TransformComponent(&Base::preUpdate, m_UpdateComponentLists);
	}

	void Manager::Update()
	{
		TransformComponent(&Base::update, m_UpdateComponentLists);
	}

	void Manager::PostUpdate()
	{
		TransformComponent(&Base::postUpdate, m_UpdateComponentLists);
	}

	void Manager::PreRender()
	{
		TransformComponent(&Base::preRender, m_RenderComponentLists);
	}

	void Manager::Render()
	{
		TransformComponent(&Base::render, m_RenderComponentLists);
	}

	void Manager::PostRender()
	{
		TransformComponent(&Base::postRender, m_RenderComponentLists);
	}

	void Manager::removeComponent(const Base* const _component)
	{
		if (!_component)return;
		
		Base* deleteComponent = nullptr;

		const s32 updatePriority = PriorityTable::GetUpdatePriorityFromId(_component->getClassId());
		if (core::InRangeSize(updatePriority, 0, m_UpdateComponentLists.size()))
		{
			auto& componentList = m_UpdateComponentLists[updatePriority];
			for (s32 i = 0; i < (s32)componentList.size(); ++i)
			{
				if (_component != componentList[i])continue;
				if (!deleteComponent)deleteComponent = componentList[i];
				componentList.erase(componentList.begin() + i);
				break;
			}
		}

		const s32 renderPriority = PriorityTable::GetRenderPriorityFromId(_component->getClassId());
		if (core::InRangeSize(renderPriority, 0, m_RenderComponentLists.size()))
		{
			auto& componentList = m_RenderComponentLists[renderPriority];
			for (s32 i = 0; i < (s32)componentList.size(); ++i)
			{
				if (_component != componentList[i])continue;
				if (!deleteComponent)deleteComponent = componentList[i];
				componentList.erase(componentList.begin() + i);
				break;
			}
		}

		if(deleteComponent)delete deleteComponent;
	}
}

CANDY_APP_NAMESPACE_END
