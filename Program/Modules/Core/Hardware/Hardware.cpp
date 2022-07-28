/*****************************************************************//**
 * \file   Hardware.cpp
 * \brief  ハードウェア
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Hardware.h"

CANDY_CORE_NAMESPACE_BEGIN

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

// 閉じる
void Hardware::Close()
{
	Impl::Close();
}

// 閉じたか
bool Hardware::IsClose()
{
	return Impl::IsClose();
}

WindowHandle Hardware::GetHwnd()
{
	return Impl::GetHwnd();
}

CANDY_CORE_NAMESPACE_END
