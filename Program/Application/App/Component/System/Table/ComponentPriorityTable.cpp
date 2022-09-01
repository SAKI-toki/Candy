/*****************************************************************//**
 * \file   ComponentPriorityTable.cpp
 * \brief  コンポーネントの優先度テーブル
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentPriorityTable.h"
#include <App/Component/System/AllComponentInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace PriorityTable::Impl
	{
		using PriorityTableType = std::vector<std::vector<const void*>>;

		// 更新処理優先度テーブル
		const PriorityTableType UpdatePriorityTable =
		{
			// 0
			{
				PlayerBehavior::GetStaticClassId(),
			},
			// 1
			{
				EnemyBehavior::GetStaticClassId(),
			},
		};

		// 描画登録処理優先度テーブル
		const PriorityTableType RenderPriorityTable =
		{
			// 0
			{
				Renderer::GetStaticClassId(),
			},
		};

		s32 GetPriorityFromId(const void* const _id, const PriorityTableType& _priorityTable)
		{
			for (s32 i = 0; i < static_cast<s32>(_priorityTable.size()); ++i)
			{
				for (auto p : _priorityTable[i])
				{
					if (p != _id)continue;
					return i;
				}
			}
			return static_cast<s32>(_priorityTable.size());
		}
	}

	s32 PriorityTable::GetUpdatePriorityFromId(const void* const _id)
	{
		return Impl::GetPriorityFromId(_id, Impl::UpdatePriorityTable);
	}

	s32 PriorityTable::GetUpdatePriorityCount()
	{
		return static_cast<s32>(Impl::UpdatePriorityTable.size());
	}

	s32 PriorityTable::GetRenderPriorityFromId(const void* const _id)
	{
		return Impl::GetPriorityFromId(_id, Impl::RenderPriorityTable);
	}

	s32 PriorityTable::GetRenderPriorityCount()
	{
		return static_cast<s32>(Impl::RenderPriorityTable.size());
	}

}

CANDY_APP_NAMESPACE_END
