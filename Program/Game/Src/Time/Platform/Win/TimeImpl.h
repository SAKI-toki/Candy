#ifndef CANDY_TIME_IMPL_H
#define CANDY_TIME_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Time::Impl
{
	void Startup();
	void Cleanup();

	f32 ToSec(const LARGE_INTEGER _value);
	f32 ToMilliSec(const LARGE_INTEGER _value);
	f32 ToMicroSec(const LARGE_INTEGER _value);
}

CANDY_NAMESPACE_END

#endif // CANDY_TIME_IMPL_H
