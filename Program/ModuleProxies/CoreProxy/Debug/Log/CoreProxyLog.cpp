/*****************************************************************//**
 * \file   CoreProxyLog.cpp
 * \brief  ログのプロキシ
 * \author Yu Ishiyama.
 * \date   2022/07/05
 *********************************************************************/

#include "CoreProxyLog.h"

#if PLATFORM_WIN
#include <CoreProxy/Platform/Win/Debug/Log/CoreProxyLogImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_PROXY_NAMESPACE_BEGIN

namespace Debug
{
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
		core::CriticalSection m_CriticalSection;

		f32 m_Timer = 0.0f;

#endif // BUILD_DEBUG
	} // namespace Log

	// ログの初期化のプロキシ
	void Log::StartupProxy()
	{
#if BUILD_DEBUG
		m_CriticalSection.startup();
#endif // BUILD_DEBUG
	}

	// ログの破棄のプロキシ
	void Log::CleanupProxy()
	{
#if BUILD_DEBUG
		m_CriticalSection.cleanup();
#endif // BUILD_DEBUG
	}

	// ログの更新のプロキシ
	void Log::UpdateProxy()
	{
#if BUILD_DEBUG
		CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);

		/*if (m_Timer >= 0.0f)
		{
			for (size_t i = 0; i < core::Min(m_LogInfos.size(), 30); ++i)
			{
				const size_t logIndex = m_LogInfos.size() - i - 1;
				const auto& logInfo = m_LogInfos[logIndex];
				DebugDraw::DrawString(core::Vec4{ 50.0f, 0.0f + i * 30.0f, 0.0f }, logInfo.m_Color, 30.0f, logInfo.m_Message.c_str());
			}
			m_Timer -= Global::GetAppTime();
		}*/

#endif // BUILD_DEBUG
	}

	// ログのプロキシ
	void Log::AddLogProxy(const Color _color, const std::string& _fileName, const s32 _lineNo,
		const std::string& _funcName, const std::string& _message)
	{
		LogInfo logInfo;
		logInfo.m_Color = _color;
		logInfo.m_FileName = _fileName;
		logInfo.m_LineNo = _lineNo;
		logInfo.m_FuncName = _funcName;
		logInfo.m_Message = _message;

		CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
		LogImpl::OutputDebugLog("%s(%d) : %s", _fileName.c_str(), _lineNo, logInfo.m_Message.c_str());
		std::printf("%s(%d) : %s\n", _fileName.c_str(), _lineNo, logInfo.m_Message.c_str());
		m_LogInfos.push_back(logInfo);

		m_Timer = 3.0f;
	}
}

CANDY_CORE_PROXY_NAMESPACE_END
