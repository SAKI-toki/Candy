/*****************************************************************//**
 * \file   Log.cpp
 * \brief  デバッグログ
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Log.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace Debug
{
	// ログの追加
	template<typename ...Types>
	void Log::AddLog(
		CANDY_UNUSED_VALUE_ATTR const Color _color,
		CANDY_UNUSED_VALUE_ATTR const std::string_view _fileName,
		CANDY_UNUSED_VALUE_ATTR const s32 _lineNo,
		CANDY_UNUSED_VALUE_ATTR const std::string_view _funcName,
		CANDY_UNUSED_VALUE_ATTR const std::string_view _format,
		CANDY_UNUSED_VALUE_ATTR Types&& ..._args)
	{
#if BUILD_DEBUG
		AddLogDirect(_color, _fileName, _lineNo, _funcName, std::format(_format, std::forward<Types>(_args)...));
#endif // BUILD_DEBUG
	}
}

CANDY_CORE_NAMESPACE_END
