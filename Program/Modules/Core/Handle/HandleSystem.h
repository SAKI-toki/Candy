/*****************************************************************//**
 * \file   HandleSystem.h
 * \brief  ハンドラシステム
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_HANDLE_SYSTEM_H
#define CANDY_CORE_HANDLE_SYSTEM_H

#include <Core/CoreInclude.h>

#include "Handle.h"
#include <Core/Utility/StaticVector/StaticVector.h>

CANDY_CORE_NAMESPACE_BEGIN

// ハンドラシステム
template<typename T, typename HandleType>
class HandleSystem
{
	using ValuePtrType = T*;
public:
	// 初期化
	void startup();
	// 破棄
	void cleanup();

	// ハンドラの生成
	HandleType createHandle(ValuePtrType _valuePtr);
	// ハンドラの解放
	void releaseHandle(const HandleType& handle);

	// ハンドラからポインタの取得
	ValuePtrType getPtr(const HandleType& handle)const;

private:
	struct Unit
	{
		ValuePtrType m_pVaule = nullptr;
		HandleType m_Handle;
	};

	std::vector<Unit> m_Units;
	StaticVector<u64, 0xffff> m_ReleaseUnitIndices;
	uint64_t m_Index = 0;
	uint64_t m_Count = 0;
};

CANDY_CORE_NAMESPACE_END

#include "HandleSystem.inl"

#endif // CANDY_CORE_HANDLE_SYSTEM_H
