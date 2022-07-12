/*****************************************************************//**
 * \file   TickImpl.h
 * \brief  ティックの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_TICK_IMPL_H
#define CANDY_CORE_TICK_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

class TickImpl
{
protected:
	TickImpl();

	// 秒
	f32 toSec()const;
	// ミリ秒
	f32 toMilliSec()const;
	// マイクロ秒
	f32 toMicroSec()const;

	// 加減関数群
	TickImpl operator+(const TickImpl& _other)const;
	TickImpl operator-(const TickImpl& _other)const;

private:
	LARGE_INTEGER m_Value{};
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_TICK_IMPL_H
