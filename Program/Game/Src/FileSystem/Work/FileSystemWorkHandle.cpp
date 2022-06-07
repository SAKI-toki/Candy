/*****************************************************************//**
 * \file   FileSystemWorkHandle.cpp
 * \brief  �t�@�C���V�X�e���̃��[�N�n���h��
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystemWorkHandle.h"
#include <FileSystem/FileSystem.h>

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	// �I������
	bool WorkHandle::isEnd()const
	{
		return FileSystem::IsEndReadWork(*this);
	}
}

CANDY_NAMESPACE_END
