/*****************************************************************//**
 * \file   FileSystemWorkHandle.h
 * \brief  �t�@�C���V�X�e���̃��[�N�n���h��
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_FILE_SYSTEM_WORK_HANDLE_H
#define CANDY_FILE_SYSTEM_WORK_HANDLE_H

#include <Handle/Handle.h>

CANDY_NAMESPACE_BEGIN

namespace FileSystem
{
	class Work;
	class WorkHandle : public Handle<Work, WorkHandle>
	{
	public:
		// �I������
		bool isEnd()const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_FILE_SYSTEM_WORK_HANDLE_H
