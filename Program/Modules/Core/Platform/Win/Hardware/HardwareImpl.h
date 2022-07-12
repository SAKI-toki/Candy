/*****************************************************************//**
 * \file   HardwareImpl.h
 * \brief  ハードウェアの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_HARDWARE_IMPL_H
#define CANDY_CORE_HARDWARE_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Hardware::Impl
{
	// 初期化情報
	struct StartupInfo
	{
		virtual ~StartupInfo() = default;

		HINSTANCE m_InstanceHandle;
		int m_CmdShowNum{};
		std::string m_Name;
		f32 m_Width{};
		f32 m_Height{};
	};

	// 初期化
	void Startup(const StartupInfo& _startupInfo);
	// 破棄
	void Cleanup();
	// 更新
	void Update();

	// 閉じたか
	bool IsClose();

	// ウィンドウハンドラの取得
	WindowHandle GetHwnd();
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_HARDWARE_IMPL_H
