/*****************************************************************//**
 * \file   ComponentManager.cpp
 * \brief  コンポーネントリスト
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentList.h"
#include <App/Component/System/Manager/ComponentManager.h>

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
	void List::addComponentInternal(Base* const _component)
	{
		const s32 addPriority = Priority::GetFromId(_component->getClassId());

		auto itr = m_Components.begin();
		while (itr != m_Components.end())
		{
			auto component = *itr;
			++itr;
			if (!component)continue;
			const s32 priority = Priority::GetFromId(component->getClassId());
			if (priority < addPriority)continue;
			break;
		}
		m_Components.insert(itr, _component);
		_component->startup();
	}

	// コンポーネントの削除
	void List::removeComponent(const Base* const _component)
	{
		if (!_component)return;
		for (s32 i = 0; i < (s32)m_Components.size(); ++i)
		{
			if (_component != m_Components[i])continue;
			removeComponentInternal(i);
			return;
		}
	}

	// コンポーネントの削除
	void List::removeComponentInternal(const s32 _index)
	{
		if (_index < 0 || _index >= (s32)m_Components.size())return;
		auto itr = m_Components.begin() + _index;
		(*itr)->cleanup();
		Manager::removeComponent(m_Components[_index]);
		m_Components.erase(itr);
	}
}

CANDY_APP_NAMESPACE_END
