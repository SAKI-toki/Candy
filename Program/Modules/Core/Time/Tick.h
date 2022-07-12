/*****************************************************************//**
 * \file   Tick.h
 * \brief  ティック
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_TICK_H
#define CANDY_CORE_TICK_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Time/TickImpl.h>
#endif

CANDY_CORE_NAMESPACE_BEGIN

class Tick : public TickImpl
{
public:
	CANDY_DEFAULT_CONSTRUCTOR_DESTRUCTOR(Tick);
	Tick(const TickImpl& _other);
	Tick(TickImpl&& _other)noexcept;

	// 秒
	f32 toSec()const;
	// ミリ秒
	f32 toMilliSec()const;
	// マイクロ秒
	f32 toMicroSec()const;

	// 加減関数群
	Tick operator+(const Tick& _other)const;
	Tick& operator+=(const Tick& _other);
	Tick operator-(const Tick& _other)const;
	Tick& operator-=(const Tick& _other);
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_TICK_H
