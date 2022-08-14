/*****************************************************************//**
 * \file   Handle.inl
 * \brief  ハンドラ
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_HANDLE_INL
#define CANDY_CORE_HANDLE_INL

#include "Handle.h"

CANDY_CORE_NAMESPACE_BEGIN

// ハンドラのクリア
template<typename T, typename DeriveType>
void Handle<T, DeriveType>::clear()
{
	m_Value = HandleValue{};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_HANDLE_INL
