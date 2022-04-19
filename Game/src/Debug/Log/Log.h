#ifndef CANDY_LOG_H
#define CANDY_LOG_H

CANDY_NAMESPACE_BEGIN

namespace Log
{
	void Startup();
	void Cleanup();
	void Update();

	void AddLog(const char* const _message, const char* const _fileName, const s32 _lineNo, const char* const _funcName);
}

#if BUILD_DEBUG
#define CANDY_LOG(MESSAGE) Log::AddLog(MESSAGE, __FILE__, __LINE__, __func__)
#else
#define CANDY_ASSERT(MESSAGE) dummyFunc(MESSAGE)
#endif // BUILD_DEBUG


CANDY_NAMESPACE_END

#endif // CANDY_LOG_H
