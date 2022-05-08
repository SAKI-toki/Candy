#ifndef CANDY_LOG_H
#define CANDY_LOG_H

CANDY_NAMESPACE_BEGIN

namespace Log
{
	void Startup();
	void Cleanup();
	void Update();

	void AddLog(const char* const _fileName, const s32 _lineNo, const char* const _funcName, const char* const _messageFmt, ...);
}

#if BUILD_DEBUG
#define CANDY_LOG(MESSAGE_FMT, ...) Log::AddLog(__FILE__, __LINE__, __func__, MESSAGE_FMT, __VA_ARGS__)
#else
#define CANDY_LOG(MESSAGE_FMT)
#endif // BUILD_DEBUG


CANDY_NAMESPACE_END

#endif // CANDY_LOG_H
