/*****************************************************************//**
 * \file   FileSystemWork.cpp
 * \brief  �t�@�C���V�X�e���̃��[�N
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemWork.h"

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// ������
	void Work::startup(const u32 _hash, std::byte* _buf)
	{
		m_Hash = _hash;
		m_Buffer = _buf;
	}

	// �j��
	void Work::cleanup()
	{

	}

	// ���[�N�n���h���̎擾
	WorkHandle Work::getHandle()const
	{
		return m_Handle;
	}

	// �n�b�V���̎擾
	u32 Work::getHash()const
	{
		return m_Hash;
	}

	// �o�b�t�@�̎擾
	std::byte* Work::getBuffer()const
	{
		return m_Buffer;
	}

	// �n���h���̃Z�b�g
	void Work::setHandle(const WorkHandle _handle)
	{
		m_Handle = _handle;
	}
}

CANDY_NAMESPACE_END
