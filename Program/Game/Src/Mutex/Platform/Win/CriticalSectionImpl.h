/*****************************************************************//**
 * \file   CriticalSectionImpl.h
 * \brief  �N���e�B�J���Z�N�V�����̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CRITICAL_SECTION_IMPL_H
#define CANDY_CRITICAL_SECTION_IMPL_H

CANDY_NAMESPACE_BEGIN

class CriticalSectionImpl
{
public:
	DEFAULT_CONSTRUCTOR_DESTRUCTOR_DELETE_COPY_MOVE(CriticalSectionImpl);

	// ������
	void startup();
	// �j��
	void cleanup();
	// �J�n
	void enter();
	// �I��
	void leave();
private:
	CRITICAL_SECTION m_CriticalSection{};
};

CANDY_NAMESPACE_END

#endif // CANDY_CRITICAL_SECTION_IMPL_H
