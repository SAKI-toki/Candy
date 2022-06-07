/*****************************************************************//**
 * \file   Hardware.h
 * \brief  ハードウェア
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_HARDWARE_H
#define CANDY_HARDWARE_H

#if PLATFORM_WIN
#include "Platform/Win/HardwareImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

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
}

CANDY_NAMESPACE_END

#endif // CANDY_HARDWARE_H
