/*****************************************************************//**
 * \file   Handle.h
 * \brief  ハンドラ
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_HANDLE_H
#define CANDY_CORE_HANDLE_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

// ハンドラの値
struct HandleValue
{
	HandleValue() = default;
	uint64_t m_Index{ static_cast<uint64_t>(-1) };
	uint64_t m_Count{ static_cast<uint64_t>(-1) };
	uint64_t m_Hash{ static_cast<uint64_t>(-1) };
	uint64_t m_User{ static_cast<uint64_t>(-1) };

	// 比較関数群
	bool operator==(const HandleValue& handle)const
	{
		return m_Index == handle.m_Index &&
			m_Count == handle.m_Count &&
			m_Hash == handle.m_Hash;
	}
	bool operator!=(const HandleValue& handle)const { return !(*this == handle); }
};

template<typename T, typename HandleType>
class HandleSystem;

// ハンドラ
template<typename T, typename DeriveType>
class Handle
{
	friend class HandleSystem<T, DeriveType>;
public:
	// ハンドラのクリア
	void clear();

	// 比較関数群
	bool operator==(const Handle& handle)const { return m_Value == handle.m_Value; }
	bool operator!=(const Handle& handle)const { return !(*this == handle); }

protected:
	HandleValue m_Value;
};

CANDY_CORE_NAMESPACE_END

#include "Handle.inl"

#endif // CANDY_CORE_HANDLE_H
