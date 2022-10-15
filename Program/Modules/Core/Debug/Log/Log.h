/*****************************************************************//**
 * \file   Log.h
 * \brief  デバッグログ
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_DEBUG_LOG_H
#define CANDY_CORE_DEBUG_LOG_H

#include <Core/CoreInclude.h>

#include <Core/Color/Color.h>
#include <Core/Color/ConvColor.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Debug
{
	namespace Log
	{
		// 初期化
		void Startup();

		// 破棄
		void Cleanup();

		// 更新
		void Update();

		// ログの追加
		template<typename ...Types>
		void AddLog(const Color _color, const std::string_view _fileName, const s32 _lineNo,
			const std::string_view _funcName, const std::string_view _format, Types&& ..._args);

		// ログの追加(直接)
		void AddLogDirect(const Color _color, const std::string_view _fileName, const s32 _lineNo,
			const std::string_view _funcName, const std::string_view _log);
	}
}

#if BUILD_DEBUG
#define CANDY_LOG_COLOR(COLOR, MESSAGE_FMT, ...)		candy::core::Debug::Log::AddLog((COLOR), __FILE__, __LINE__, __func__, (MESSAGE_FMT), __VA_ARGS__)

#define CANDY_LOG(MESSAGE_FMT, ...)						CANDY_LOG_COLOR(WhiteColor,		(MESSAGE_FMT), __VA_ARGS__)
#define CANDY_LOG_ERR(MESSAGE_FMT, ...)					CANDY_LOG_COLOR(RedColor,		(MESSAGE_FMT), __VA_ARGS__)
#define CANDY_LOG_WARN(MESSAGE_FMT, ...)				CANDY_LOG_COLOR(YellowColor,	(MESSAGE_FMT), __VA_ARGS__)
#else
#define CANDY_LOG_COLOR(...)

#define CANDY_LOG(...)
#define CANDY_LOG_ERR(...)
#define CANDY_LOG_WARN(...)
#endif // BUILD_DEBUG


CANDY_CORE_NAMESPACE_END

#include "Log.inl"

#endif // CANDY_CORE_DEBUG_LOG_H
