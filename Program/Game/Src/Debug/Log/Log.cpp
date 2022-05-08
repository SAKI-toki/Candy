#include "Log.h"
#include <Mutex/CriticalSection.h>

#if PLATFORM_WIN
#include "Platform/Win/LogImpl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Log
{
#if BUILD_DEBUG
	struct LogInfo
	{
		std::string m_Message;
		std::string m_FileName;
		s32 m_LineNo{};
		std::string m_FuncName;
	};
	std::vector<LogInfo> m_LogInfos;
	CriticalSection m_CriticalSection;

#endif // BUILD_DEBUG
}

void Log::Startup()
{
#if BUILD_DEBUG
	m_CriticalSection.startup();
#endif // BUILD_DEBUG
}

void Log::Cleanup()
{
#if BUILD_DEBUG
	m_CriticalSection.cleanup();
#endif // BUILD_DEBUG
}

void Log::Update()
{
#if BUILD_DEBUG
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
#endif // BUILD_DEBUG
}

void Log::AddLog(const char* const _fileName, const s32 _lineNo, const char* const _funcName, const char* const _messageFmt, ...)
{
#if BUILD_DEBUG

	LogInfo logInfo;
	logInfo.m_FileName = _fileName;
	logInfo.m_LineNo = _lineNo;
	logInfo.m_FuncName = _funcName;

	va_list args;
	va_start(args, _messageFmt);
	char buf[4096];
	vsprintf(buf, _messageFmt, args);
	va_end(args);
	logInfo.m_Message = buf;

	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	LogImpl::OutputDebugLog("%s(%d) : %s", _fileName, _lineNo, logInfo.m_Message.c_str());
	m_LogInfos.push_back(logInfo);
#else
	CANDY_UNUSED_VALUE(_messageFmt);
	CANDY_UNUSED_VALUE(_fileName);
	CANDY_UNUSED_VALUE(_lineNo);
	CANDY_UNUSED_VALUE(_funcName);
#endif // BUILD_DEBUG
}

CANDY_NAMESPACE_END
