/*****************************************************************//**
 * \file   CoreAdjustAlign.cpp
 * \brief  アライメント調整
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "CoreAdjustAlign.h"

CANDY_CORE_NAMESPACE_BEGIN

u64 AlignAdjust(const u64 _size, const u64 _alignment)
{
	if (_size == 0)return 0;
	
	return (_size + (_alignment - 1) & ~(_alignment - 1));
}

CANDY_CORE_NAMESPACE_END
