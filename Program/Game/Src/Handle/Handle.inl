/*****************************************************************//**
 * \file   Handle.inl
 * \brief  �n���h��
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Handle.h"

CANDY_NAMESPACE_BEGIN

// �n���h���̃N���A
template<typename T, typename DeriveType>
void Handle<T, DeriveType>::clear()
{
	m_Value = HandleValue{};
}

CANDY_NAMESPACE_END
