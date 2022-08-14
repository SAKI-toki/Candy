/*****************************************************************//**
 * \file   HandleSystem.inl
 * \brief  ハンドラシステム
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_HANDLE_SYSTEM_INL
#define CANDY_CORE_HANDLE_SYSTEM_INL

#include "HandleSystem.h"

CANDY_CORE_NAMESPACE_BEGIN

// 初期化
template<typename T, typename HandleType>
void HandleSystem<T, HandleType>::startup()
{
	m_Count = 0;
	m_Index = 0;
	m_Units.clear();
	m_Units.resize(0xffff);
	m_ReleaseUnitIndices.clear();
}

// 破棄
template<typename T, typename HandleType>
void HandleSystem<T, HandleType>::cleanup()
{
	m_Count = 0;
	m_Index = 0;
	m_Units.clear();
	m_ReleaseUnitIndices.clear();
}

// ハンドラの生成
template<typename T, typename HandleType>
HandleType HandleSystem<T, HandleType>::createHandle(ValuePtrType _valuePtr)
{
	HandleType handle;
	if (!_valuePtr)return handle;
	if (m_Units.empty())return handle;
	if (m_Count == 0xffff)return handle;

	if (!m_ReleaseUnitIndices.empty())
	{
		auto itr = m_ReleaseUnitIndices.end() - 1;
		uint64_t index = *itr;
		m_ReleaseUnitIndices.erase(itr);
		handle.m_Value.m_Index = index;
		handle.m_Value.m_Count = ++m_Count;
		handle.m_Value.m_Hash = reinterpret_cast<uint64_t>(_valuePtr);
		m_Units[index].m_pVaule = _valuePtr;
		m_Units[index].m_Handle = handle;
		return handle;
	}
	if (m_Index == 0xffff)
	{
		return handle;
	}
	handle.m_Value.m_Index = m_Index;
	handle.m_Value.m_Count = ++m_Count;
	handle.m_Value.m_Hash = reinterpret_cast<uint64_t>(_valuePtr);
	m_Units[m_Index].m_pVaule = _valuePtr;
	m_Units[m_Index].m_Handle = handle;
	++m_Index;
	return handle;
}

// ハンドラの解放
template<typename T,typename HandleType>
void HandleSystem<T, HandleType>::releaseHandle(HandleType handle)
{
	if (m_Units.empty())return;
	if (m_Units[handle.m_Value.m_Index].m_Handle != handle)return;
	m_Units[handle.m_Value.m_Index].m_pVaule = nullptr;
	m_Units[handle.m_Value.m_Index].m_Handle.clear();
	m_ReleaseUnitIndices.push_back(handle.m_Value.m_Index);
}

// ハンドラからポインタの取得
template<typename T, typename HandleType>
HandleSystem<T, HandleType>::ValuePtrType HandleSystem<T, HandleType>::getPtr(HandleType handle)const
{
	if (m_Units.empty())return nullptr;
	if (handle.m_Value.m_Index == static_cast<u64>(-1))return nullptr;
	if (m_Units[handle.m_Value.m_Index].m_Handle != handle)return nullptr;
	return m_Units[handle.m_Value.m_Index].m_pVaule;
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_HANDLE_SYSTEM_INL
