/*****************************************************************//**
 * \file   ComponentPriority.h
 * \brief  コンポーネントの優先度
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_PRORITY_H
#define CANDY_APP_COMPONENT_PRORITY_H

#include <App/AppInclude.h>
#include <App/Component/ComponentDef.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	namespace Priority
	{
		template<typename T, is_base_component_interface_t<T> = nullptr>
		s32 GetFromType();

		s32 GetFromId(const void* const _id);

		s32 GetCount();
	}
}

CANDY_APP_NAMESPACE_END

#include "ComponentPriority.inl"

#endif // CANDY_APP_COMPONENT_PRORITY_H
