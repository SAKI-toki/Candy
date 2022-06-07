/*****************************************************************//**
 * \file   HandleSystem.h
 * \brief  �n���h���V�X�e��
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_HANDLE_SYSTEM_H
#define CANDY_HANDLE_SYSTEM_H

#include "Handle.h"
#include <StaticVector/StaticVector.h>

CANDY_NAMESPACE_BEGIN

// �n���h���V�X�e��
template<typename T, typename HandleType>
class HandleSystem
{
	using ValuePtrType = T*;
public:
	// ������
	void startup();
	// �j��
	void cleanup();

	// �n���h���̐���
	HandleType createHandle(ValuePtrType _valuePtr);
	// �n���h���̉��
	void releaseHandle(HandleType handle);

	// �n���h������|�C���^�̎擾
	ValuePtrType getPtr(HandleType handle)const;

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

CANDY_NAMESPACE_END

#include "HandleSystem.inl"

#endif // CANDY_HANDLE_SYSTEM_H
