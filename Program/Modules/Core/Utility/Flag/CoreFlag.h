/*****************************************************************//**
 * \file   CoreFlag.h
 * \brief  フラグ管理クラス
 * \author Yu Ishiyama.
 * \date   2022/11/05
 *********************************************************************/

#ifndef CANDY_CORE_FLAG_H
#define CANDY_CORE_FLAG_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

template<typename T>
class Flag
{
public:
	void onFlag(const T _v);
	void offFlag(const T _v);

	bool isFlag(const T _v)const;

private:
	u32 m_Value{};
};

CANDY_CORE_NAMESPACE_END

#include "CoreFlag.inl"

#endif // CANDY_CORE_FLAG_H
