/*****************************************************************//**
 * \file   Hardware.h
 * \brief  ハードウェア
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_HARDWARE_H
#define CANDY_CORE_HARDWARE_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Hardware/HardwareImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_NAMESPACE_BEGIN

namespace Hardware
{
	struct StartupInfo : Impl::StartupInfo
	{

	};

	// 初期化
	void Startup(const StartupInfo& _startupInfo);
	// 破棄
	void Cleanup();
	// 更新
	void Update();

	// 閉じたか
	bool IsClose();

	WindowHandle GetHwnd();
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_HARDWARE_H
