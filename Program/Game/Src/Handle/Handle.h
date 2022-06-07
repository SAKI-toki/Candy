/*****************************************************************//**
 * \file   Handle.h
 * \brief  �n���h��
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_HANDLE_H
#define CANDY_HANDLE_H

CANDY_NAMESPACE_BEGIN

// �n���h���̒l
struct HandleValue
{
	HandleValue() = default;
	uint64_t m_Index{ static_cast<uint64_t>(-1) };
	uint64_t m_Count{ static_cast<uint64_t>(-1) };
	uint64_t m_Hash{ static_cast<uint64_t>(-1) };
	uint64_t m_User{ static_cast<uint64_t>(-1) };

	// ��r�֐��Q
	bool operator==(const HandleValue& handle)
	{
		return m_Index == handle.m_Index &&
			m_Count == handle.m_Count &&
			m_Hash == handle.m_Hash;
	}
	bool operator!=(const HandleValue& handle) { return !(*this == handle); }
};

template<typename T, typename HandleType>
class HandleSystem;

// �n���h��
template<typename T, typename DeriveType>
class Handle
{
	friend class HandleSystem<T, DeriveType>;
public:
	// �n���h���̃N���A
	void clear();

	// ��r�֐��Q
	bool operator==(const Handle& handle) { return m_Value == handle.m_Value; }
	bool operator!=(const Handle& handle) { return !(*this == handle); }

protected:
	HandleValue m_Value;
};

CANDY_NAMESPACE_END

#include "Handle.inl"

#endif // CANDY_HANDLE_H
