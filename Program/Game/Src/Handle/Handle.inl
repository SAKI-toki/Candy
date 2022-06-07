/*****************************************************************//**
 * \file   Handle.inl
 * \brief  ハンドラ
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Handle.h"

CANDY_NAMESPACE_BEGIN

// ハンドラのクリア
template<typename T, typename DeriveType>
void Handle<T, DeriveType>::clear()
{
	m_Value = HandleValue{};
}

CANDY_NAMESPACE_END
