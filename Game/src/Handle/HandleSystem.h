#ifndef CANDY_HANDLE_SYSTEM_H
#define CANDY_HANDLE_SYSTEM_H

#include "Handle.h"
#include <StaticVector/StaticVector.h>

CANDY_NAMESPACE_BEGIN

template<typename T, typename HandleType>
class HandleSystem
{
	using ValuePtrType = T*;
public:
	void startup();
	void cleanup();

	HandleType createHandle(ValuePtrType _valuePtr);
	void releaseHandle(HandleType handle);

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
