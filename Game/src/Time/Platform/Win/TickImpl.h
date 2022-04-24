#ifndef CANDY_TICK_IMPL_H
#define CANDY_TICK_IMPL_H

CANDY_NAMESPACE_BEGIN

class TickImpl
{
public:
	TickImpl();

	f32 toSec()const;
	f32 toMilliSec()const;
	f32 toMicroSec()const;

	TickImpl operator+(const TickImpl& _other)const;
	TickImpl& operator+=(const TickImpl& _other);
	TickImpl operator-(const TickImpl& _other)const;
	TickImpl& operator-=(const TickImpl& _other);

private:
	LARGE_INTEGER m_Value{};
};

CANDY_NAMESPACE_END

#endif // CANDY_TICK_IMPL_H
