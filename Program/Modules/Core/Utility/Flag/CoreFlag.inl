/*****************************************************************//**
 * \file   CoreFlag.inl
 * \brief  フラグ管理クラス
 * \author Yu Ishiyama.
 * \date   2022/11/05
 *********************************************************************/

#ifndef CANDY_CORE_FLAG_INL
#define CANDY_CORE_FLAG_INL

#include "CoreFlag.h"

CANDY_CORE_NAMESPACE_BEGIN

template<typename T>
void Flag<T>::onFlag(const T _v)
{
	m_Value &= static_cast<u32>(1 << (static_cast<s32>(_v)));
}

template<typename T>
void Flag<T>::offFlag(const T _v)
{
	m_Value |= ~(static_cast<u32>(1 << (static_cast<s32>(_v))));
}

template<typename T>
bool Flag<T>::isFlag(const T _v)const
{
	return m_Value & static_cast<u32>(1 << (static_cast<s32>(_v)));
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FLAG_INL
