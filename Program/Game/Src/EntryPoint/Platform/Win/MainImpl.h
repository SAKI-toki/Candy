/*****************************************************************//**
 * \file   MainImpl.h
 * \brief  �G���g���[�|�C���g�̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_MAIN_IMPL_H
#define CANDY_MAIN_IMPL_H

CANDY_NAMESPACE_BEGIN

#define ENTRY_POINT_MAIN() int WINAPI WinMain( \
_In_ HINSTANCE _hInstance, \
_In_opt_ HINSTANCE _hPrevInstance, \
_In_ LPSTR _lpCmdLine, \
_In_ int _nShowCmd)

#define ENTRY_POINT_STARTUP() candy::entryPointStartup(_hInstance, _hPrevInstance, _lpCmdLine, _nShowCmd)
#define ENTRY_POINT_CLEANUP() candy::entryPointCleanup(_hInstance, _hPrevInstance, _lpCmdLine, _nShowCmd)
#define RETURN_ENTRY_POINT() return 0

// �G���g���[�|�C���g����̏�����
void entryPointStartup(_In_ HINSTANCE _instanceHandle,
	_In_opt_ HINSTANCE _prevInstanceHandle,
	_In_ LPSTR _cmdLineStr,
	_In_ int _cmdShowNum);

// �G���g���[�|�C���g�I�����O�̔j��
void entryPointCleanup(_In_ HINSTANCE _instanceHandle,
	_In_opt_ HINSTANCE _prevInstanceHandle,
	_In_ LPSTR _cmdLineStr,
	_In_ int _cmdShowNum);

CANDY_NAMESPACE_END

#endif // CANDY_MAIN_IMPL_H
