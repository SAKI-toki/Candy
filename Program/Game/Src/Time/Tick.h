#ifndef CANDY_TICK_H
#define CANDY_TICK_H

#if PLATFORM_WIN
#include "Platform/Win/TickImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

class Tick : public TickImpl
{

};

CANDY_NAMESPACE_END

#endif // CANDY_TICK_H
