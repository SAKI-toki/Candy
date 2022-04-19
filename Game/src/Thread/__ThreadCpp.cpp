#include "Thread.cpp"
#include "ThreadSystem.cpp"

#if PLATFORM_WIN
#include "Platform/Win/ThreadHandle.cpp"
#include "Platform/Win/ThreadSystemImpl.cpp"
#endif
