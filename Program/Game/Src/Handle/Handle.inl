#include "Handle.h"

CANDY_NAMESPACE_BEGIN

template<typename T, typename DeriveType>
void Handle<T, DeriveType>::clear()
{
	m_Value = HandleValue{};
}

CANDY_NAMESPACE_END
