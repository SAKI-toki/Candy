#ifndef CANDY_TIME_H
#define CANDY_TIME_H

#include "Tick.h"

CANDY_NAMESPACE_BEGIN

namespace Time
{
	void Startup();
	void Cleanup();

	Tick GetTick();
}

CANDY_NAMESPACE_END

#endif // CANDY_TIME_H
