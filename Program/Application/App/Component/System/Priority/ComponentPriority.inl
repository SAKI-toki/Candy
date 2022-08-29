/*****************************************************************//**
 * \file   ComponentPriority.inl
 * \brief  コンポーネントの優先度
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_PRORITY_INL
#define CANDY_APP_COMPONENT_PRORITY_INL

#include "ComponentPriority.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	template<typename T, is_base_component_interface_t<T>>
	s32 Priority::GetFromType()
	{
		return GetFromId(T::GetStaticClassId());
	}
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_PRORITY_INL
