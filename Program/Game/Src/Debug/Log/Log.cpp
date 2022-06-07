/*****************************************************************//**
 * \file   Log.cpp
 * \brief  デバッグログ
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

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
		Color m_Color;
		std::string m_Message;
		std::string m_FileName;
		s32 m_LineNo{};
		std::string m_FuncName;
	};
	std::vector<LogInfo> m_LogInfos;
	CriticalSection m_CriticalSection;

	f32 m_Timer = 0.0f;

#endif // BUILD_DEBUG
}

// 初期化
void Log::Startup()
{
#if BUILD_DEBUG
	m_CriticalSection.startup();
#endif // BUILD_DEBUG
}

// 破棄
void Log::Cleanup()
{
#if BUILD_DEBUG
	m_CriticalSection.cleanup();
#endif // BUILD_DEBUG
}

// 更新
void Log::Update()
{
#if BUILD_DEBUG
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);

	if (m_Timer >= 0.0f)
	{
		for (size_t i = 0; i < Min(m_LogInfos.size(), 30); ++i)
		{
			const size_t logIndex = m_LogInfos.size() - i - 1;
			const auto& logInfo = m_LogInfos[logIndex];
			DebugDraw::DrawString(Vec4{ 50.0f, 0.0f + i * 30.0f, 0.0f }, logInfo.m_Color, 30.0f, logInfo.m_Message.c_str());
		}
		m_Timer -= Global::GetAppTime();
	}

#endif // BUILD_DEBUG
}

// ログの追加
void Log::AddLog(const Color _color, const char* const _fileName, const s32 _lineNo, const char* const _funcName, const char* const _messageFmt, ...)
{
#if BUILD_DEBUG
	LogInfo logInfo;
	logInfo.m_Color = _color;
	logInfo.m_FileName = _fileName;
	logInfo.m_LineNo = _lineNo;
	logInfo.m_FuncName = _funcName;

	char buf[4096];
	va_list vaList;
	va_start(vaList, _messageFmt);
	vsprintf(buf, _messageFmt, vaList);
	va_end(vaList);
	logInfo.m_Message = buf;

	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	LogImpl::OutputDebugLog("%s(%d) : %s", _fileName, _lineNo, logInfo.m_Message.c_str());
	std::printf("%s(%d) : %s\n", _fileName, _lineNo, logInfo.m_Message.c_str());
	m_LogInfos.push_back(logInfo);

	m_Timer = 3.0f;
#else
	CANDY_UNUSED_VALUE(_color);
	CANDY_UNUSED_VALUE(_fileName);
	CANDY_UNUSED_VALUE(_lineNo);
	CANDY_UNUSED_VALUE(_funcName);
	CANDY_UNUSED_VALUE(_messageFmt);
#endif // BUILD_DEBUG
}


CANDY_NAMESPACE_END
