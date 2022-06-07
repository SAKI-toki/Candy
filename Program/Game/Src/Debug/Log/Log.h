/*****************************************************************//**
 * \file   Log.h
 * \brief  デバッグログ
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_LOG_H
#define CANDY_DEBUG_LOG_H

#include <Color/Color.h>
#include <Color/ConvColor.h>

CANDY_NAMESPACE_BEGIN

namespace Log
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();

	// ログの追加
	void AddLog(const Color _color, const char* const _fileName, const s32 _lineNo, const char* const _funcName, const char* const _messageFmt, ...);
}

#if BUILD_DEBUG
#define CANDY_LOG_COLOR(COLOR, MESSAGE_FMT, ...) Log::AddLog((COLOR), __FILE__, __LINE__, __func__, (MESSAGE_FMT), __VA_ARGS__)

#define CANDY_LOG(MESSAGE_FMT, ...)					CANDY_LOG_COLOR(GetColorRGB32(0x00, 0x00, 0x00), (MESSAGE_FMT), __VA_ARGS__)
#define CANDY_LOG_ERR(MESSAGE_FMT, ...)				CANDY_LOG_COLOR(GetColorRGB32(0xff, 0x00, 0x00), (MESSAGE_FMT), __VA_ARGS__)
#define CANDY_LOG_WARN(MESSAGE_FMT, ...)			CANDY_LOG_COLOR(GetColorRGB32(0xff, 0xff, 0x00), (MESSAGE_FMT), __VA_ARGS__)
#else
#define CANDY_LOG_COLOR(...)

#define CANDY_LOG(...)
#define CANDY_LOG_ERR(...)
#define CANDY_LOG_WARN(...)
#endif // BUILD_DEBUG


CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_LOG_H
