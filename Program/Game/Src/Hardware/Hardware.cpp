/*****************************************************************//**
 * \file   Hardware.cpp
 * \brief  ハードウェア
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Hardware.h"

CANDY_NAMESPACE_BEGIN

// 初期化
void Hardware::Startup(const StartupInfo& _startupInfo)
{
	Impl::Startup(_startupInfo);
}

// 破棄
void Hardware::Cleanup()
{
	Impl::Cleanup();
}

// 更新
void Hardware::Update()
{
	Impl::Update();
}

// 閉じたか
bool Hardware::IsClose()
{
	return Impl::IsClose();
}

CANDY_NAMESPACE_END
