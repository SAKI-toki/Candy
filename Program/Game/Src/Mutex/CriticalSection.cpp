/*****************************************************************//**
 * \file   CriticalSection.cpp
 * \brief  �N���e�B�J���Z�N�V����
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#include "CriticalSection.h"

CANDY_NAMESPACE_BEGIN

// ������
void CriticalSection::startup()
{
	CriticalSectionImpl::startup();
}
// �j��
void CriticalSection::cleanup()
{
	CriticalSectionImpl::cleanup();
}
// �J�n
void CriticalSection::enter()
{
	CriticalSectionImpl::enter();
}
// �I��
void CriticalSection::leave()
{
	CriticalSectionImpl::leave();
}

CANDY_NAMESPACE_END
