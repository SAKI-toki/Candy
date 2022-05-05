#include "Time.cpp"
#include "Tick.cpp"

#if PLATFORM_WIN
#include "Platform/Win/TimeImpl.cpp"
#include "Platform/Win/TickImpl.cpp"
#endif