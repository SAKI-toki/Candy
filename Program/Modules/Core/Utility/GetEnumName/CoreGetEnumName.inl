/*****************************************************************//**
 * \file   CoreGetEnumName.inl
 * \brief  enum名の取得
 * \author Yu Ishiyama.
 * \date   2022/07/24
 *********************************************************************/

#include "CoreGetEnumName.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace GetEnumNameDetail
{
	template<typename EnumT, EnumT EnumV>
	inline std::string GetEnumNameImpl()
	{
		return __FUNCSIG__;
	}
}

template<auto EnumV>
inline std::string GetEnumName()
{
	return GetEnumNameDetail::GetEnumNameImpl<decltype(EnumV),EnumV>();
}

CANDY_CORE_NAMESPACE_END
