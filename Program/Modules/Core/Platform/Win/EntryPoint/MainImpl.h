/*****************************************************************//**
 * \file   MainImpl.h
 * \brief  エントリーポイントの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_MAIN_IMPL_H
#define CANDY_CORE_MAIN_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

#define ENTRY_POINT_MAIN() int WINAPI WinMain( \
_In_ HINSTANCE _hInstance, \
_In_opt_ HINSTANCE _hPrevInstance, \
_In_ LPSTR _lpCmdLine, \
_In_ int _nShowCmd)

#define ENTRY_POINT_STARTUP() candy::core::entryPointStartup(_hInstance, _hPrevInstance, _lpCmdLine, _nShowCmd)
#define ENTRY_POINT_CLEANUP() candy::core::entryPointCleanup(_hInstance, _hPrevInstance, _lpCmdLine, _nShowCmd)
#define RETURN_ENTRY_POINT() return 0

// エントリーポイント直後の初期化
void entryPointStartup(_In_ HINSTANCE _instanceHandle,
	_In_opt_ HINSTANCE _prevInstanceHandle,
	_In_ LPSTR _cmdLineStr,
	_In_ int _cmdShowNum);

// エントリーポイント終了直前の破棄
void entryPointCleanup(_In_ HINSTANCE _instanceHandle,
	_In_opt_ HINSTANCE _prevInstanceHandle,
	_In_ LPSTR _cmdLineStr,
	_In_ int _cmdShowNum);

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MAIN_IMPL_H
