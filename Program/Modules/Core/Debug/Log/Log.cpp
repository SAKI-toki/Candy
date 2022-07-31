/*****************************************************************//**
 * \file   Log.cpp
 * \brief  デバッグログ
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Log.h"
#include <Core/Mutex/CriticalSection.h>
#include <CoreProxy/Debug/Log/CoreProxyLog.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Debug
{

	// 初期化
	void Log::Startup()
	{
#if BUILD_DEBUG
		coreProxy::Debug::Log::StartupProxy();
#endif // BUILD_DEBUG
	}

	// 破棄
	void Log::Cleanup()
	{
#if BUILD_DEBUG
		coreProxy::Debug::Log::CleanupProxy();
#endif // BUILD_DEBUG
	}

	// 更新
	void Log::Update()
	{
#if BUILD_DEBUG
		coreProxy::Debug::Log::UpdateProxy();
#endif // BUILD_DEBUG
	}

	// ログの追加(直接)
	void Log::AddLogDirect(
		CANDY_UNUSED_VALUE_ATTR const Color _color,
		CANDY_UNUSED_VALUE_ATTR const std::string_view _fileName,
		CANDY_UNUSED_VALUE_ATTR const s32 _lineNo,
		CANDY_UNUSED_VALUE_ATTR const std::string_view _funcName, 
		CANDY_UNUSED_VALUE_ATTR const std::string_view _message)
	{
#if BUILD_DEBUG
		coreProxy::Debug::Log::AddLogProxy(_color, _fileName, _lineNo, _funcName, _message);
#endif // BUILD_DEBUG
	}
}

CANDY_CORE_NAMESPACE_END
