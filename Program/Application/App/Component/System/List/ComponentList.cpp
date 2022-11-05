/*****************************************************************//**
 * \file   ComponentManager.cpp
 * \brief  コンポーネントリスト
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentList.h"
#include <App/Component/ComponentBase.h>
#include <App/Component/System/Manager/ComponentManager.h>
#include <App/Component/System/Table/ComponentPriorityTable.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	List::List()
	{

	}

	List::~List()
	{
		clear();
	}

	// クリア
	void List::clear()
	{
		for (s32 i = (s32)m_Components.size() - 1; i >= 0; --i)
		{
			removeComponentInternal(i);
		}
	}

	// コンポーネントの追加
	void List::addComponentInternal(const std::weak_ptr<ComponentBase>& _component)
	{
		auto sharedComponent = _component.lock();
		if (!sharedComponent)return;

		const s32 addPriority = PriorityTable::GetUpdatePriorityFromId(sharedComponent->getClassId());

		auto itr = m_Components.begin();
		while (itr != m_Components.end())
		{
			auto component = itr->lock();
			++itr;
			if (!component)continue;
			const s32 priority = PriorityTable::GetUpdatePriorityFromId(component->getClassId());
			if (priority < addPriority)continue;
			break;
		}
		m_Components.insert(itr, _component);
		sharedComponent->initialize();
	}

	// コンポーネントの削除
	void List::removeComponent(const std::weak_ptr<ComponentBase>& _component)
	{
		auto sharedComponent = _component.lock();
		if (!sharedComponent)return;
		for (s32 i = 0; i < (s32)m_Components.size(); ++i)
		{
			auto component = m_Components[i].lock();
			if (!component)continue;
			if (sharedComponent != component)continue;
			removeComponentInternal(i);
			return;
		}
	}

	// コンポーネントの削除
	void List::removeComponentInternal(const s32 _index)
	{
		if (_index < 0 || _index >= (s32)m_Components.size())return;
		auto itr = m_Components.begin() + _index;
		if (auto sharedComponent = itr->lock())
		{
			sharedComponent->cleanup();
		}
		Manager::removeComponent(m_Components[_index]);
		m_Components.erase(itr);
	}
}

CANDY_APP_NAMESPACE_END
