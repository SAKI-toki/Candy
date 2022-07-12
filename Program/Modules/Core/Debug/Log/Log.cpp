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

	// ログの追加
	void Log::AddLog(const Color _color, const char* const _fileName, const s32 _lineNo, const char* const _funcName, const char* const _messageFmt, ...)
	{
#if BUILD_DEBUG
		char message[4096];
		va_list vaList;
		va_start(vaList, _messageFmt);
		vsprintf(message, _messageFmt, vaList);
		va_end(vaList);
		coreProxy::Debug::Log::AddLogProxy(_color, _fileName, _lineNo, _funcName, message);
#else
		CANDY_UNUSED_VALUE(_color);
		CANDY_UNUSED_VALUE(_fileName);
		CANDY_UNUSED_VALUE(_lineNo);
		CANDY_UNUSED_VALUE(_funcName);
		CANDY_UNUSED_VALUE(_messageFmt);
#endif // BUILD_DEBUG
	}

}

CANDY_CORE_NAMESPACE_END
