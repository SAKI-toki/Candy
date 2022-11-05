/*****************************************************************//**
 * \file   ComponentPriorityTable.inl
 * \brief  コンポーネントの優先度テーブル
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_PRORITY_TABLE_INL
#define CANDY_APP_COMPONENT_PRORITY_TABLE_INL

#include "ComponentPriorityTable.h"

CANDY_APP_NAMESPACE_BEGIN

template<typename T, IsBaseComponentComponentInterfaceT<T>>
s32 PriorityTable::GetUpdatePriorityFromType()
{
	return GetUpdatePriorityFromId(T::GetStaticClassId());
}

template<typename T, IsBaseComponentComponentInterfaceT<T>>
s32 PriorityTable::GetRenderPriorityFromType()
{
	return GetRenderPriorityFromId(T::GetStaticClassId());
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_PRORITY_TABLE_INL
