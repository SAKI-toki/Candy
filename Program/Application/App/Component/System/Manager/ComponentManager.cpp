/*****************************************************************//**
 * \file   ComponentManager.cpp
 * \brief  コンポーネント管理クラス
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentManager.h"
#include <App/Component/ComponentBase.h>

CANDY_APP_NAMESPACE_BEGIN

namespace ComponentManager
{
	core::JobSystem m_JobSystem;

	void TransformAllComponentImpl(void(ComponentBase::* _baseFunc)(), std::vector<std::shared_ptr<ComponentBase>>& _componentList, std::atomic<int>& _index)
	{
		while (true)
		{
			const s32 localIndex = _index++;
			if (localIndex >= (s32)_componentList.size())break;

			auto& component = _componentList[localIndex];
			if (!component)continue;

			((*component).*_baseFunc)();
		}
	}

	void TransformAllComponent(void(ComponentBase::* _baseFunc)(), std::vector<std::vector<std::shared_ptr<ComponentBase>>>& _componentLists)
	{
		if (!_baseFunc)return;

		std::atomic<s32> index = 0;

		for (s32 i = 0; i < (s32)_componentLists.size(); ++i)
		{
			auto& componentList = _componentLists[i];

			index = 0;
			m_JobSystem.reset();
			m_JobSystem.setFunction(
				[&_baseFunc, &componentList, &index]() { TransformAllComponentImpl(_baseFunc, componentList, index); },
				m_JobSystem.getThreadCount());

			m_JobSystem.execute();
			m_JobSystem.wait();
		}
	}
}

void ComponentManager::Startup()
{
	m_UpdateComponentLists.resize(PriorityTable::GetUpdatePriorityCount());
	m_RenderComponentLists.resize(PriorityTable::GetRenderPriorityCount());
	s32 coreNoList[] = { 0, 2, 3, 4 };
	m_JobSystem.startup(coreNoList, core::GetArraySize(coreNoList));
}

void ComponentManager::Cleanup()
{
	m_JobSystem.cleanup();
	m_UpdateComponentLists.clear();
	m_RenderComponentLists.clear();
}

void ComponentManager::PreUpdate()
{
	TransformAllComponent(&ComponentBase::preUpdate, m_UpdateComponentLists);
}

void ComponentManager::Update()
{
	TransformAllComponent(&ComponentBase::update, m_UpdateComponentLists);
}

void ComponentManager::PostUpdate()
{
	TransformAllComponent(&ComponentBase::postUpdate, m_UpdateComponentLists);
}

void ComponentManager::PreRender()
{
	TransformAllComponent(&ComponentBase::preRender, m_RenderComponentLists);
}

void ComponentManager::Render()
{
	TransformAllComponent(&ComponentBase::render, m_RenderComponentLists);
}

void ComponentManager::PostRender()
{
	TransformAllComponent(&ComponentBase::postRender, m_RenderComponentLists);
}

void ComponentManager::removeComponent(const std::weak_ptr<ComponentBase>& _component)
{
	auto sharedComponent = _component.lock();
	if (!sharedComponent)return;

	for (s32 i = 0; i < (s32)m_AllComponentLists.size(); ++i)
	{
		if (sharedComponent != m_AllComponentLists[i])continue;
		m_AllComponentLists.erase(m_AllComponentLists.begin() + i);
		break;
	}

	const s32 updatePriority = PriorityTable::GetUpdatePriorityFromId(sharedComponent->getClassId());
	if (core::InRangeSize(updatePriority, 0, m_UpdateComponentLists.size()))
	{
		auto& componentList = m_UpdateComponentLists[updatePriority];
		for (s32 i = 0; i < (s32)componentList.size(); ++i)
		{
			if (sharedComponent != componentList[i])continue;
			componentList.erase(componentList.begin() + i);
			break;
		}
	}

	const s32 renderPriority = PriorityTable::GetRenderPriorityFromId(sharedComponent->getClassId());
	if (core::InRangeSize(renderPriority, 0, m_RenderComponentLists.size()))
	{
		auto& componentList = m_RenderComponentLists[renderPriority];
		for (s32 i = 0; i < (s32)componentList.size(); ++i)
		{
			if (sharedComponent != componentList[i])continue;
			componentList.erase(componentList.begin() + i);
			break;
		}
	}
}

CANDY_APP_NAMESPACE_END
