/*****************************************************************//**
 * \file   CriticalSectionImpl.cpp
 * \brief  �N���e�B�J���Z�N�V�����̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#include "CriticalSectionImpl.h"

CANDY_NAMESPACE_BEGIN

// ������
void CriticalSectionImpl::startup()
{
	::InitializeCriticalSection(&m_CriticalSection);
}
// �j��
void CriticalSectionImpl::cleanup()
{
	::DeleteCriticalSection(&m_CriticalSection);
}
// �J�n
void CriticalSectionImpl::enter()
{
	::EnterCriticalSection(&m_CriticalSection);
}
// �I��
void CriticalSectionImpl::leave()
{
	::LeaveCriticalSection(&m_CriticalSection);
}

CANDY_NAMESPACE_END
