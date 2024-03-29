﻿/*****************************************************************//**
 * \file   MainImpl.cpp
 * \brief  エントリーポイントの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/
#include "MainImpl.h"
#include <Core/Hardware/Hardware.h>

CANDY_CORE_NAMESPACE_BEGIN

// エントリーポイント直後の初期化
void entryPointStartup(_In_ HINSTANCE _instanceHandle,
	_In_opt_ HINSTANCE _prevInstanceHandle,
	_In_ LPSTR _cmdLineStr,
	_In_ int _cmdShowNum)
{
	CANDY_UNUSED_VALUE(_prevInstanceHandle);
	CANDY_UNUSED_VALUE(_cmdLineStr);

	Hardware::StartupInfo hardwareStartupInfo;
	hardwareStartupInfo.m_InstanceHandle = _instanceHandle;
	hardwareStartupInfo.m_CmdShowNum = _cmdShowNum;
	hardwareStartupInfo.m_Name = Config::GetAppName();
	hardwareStartupInfo.m_Width = 1600;
	hardwareStartupInfo.m_Height = 900;
	Hardware::Startup(hardwareStartupInfo);
}

// エントリーポイント終了直前の破棄
void entryPointCleanup(_In_ HINSTANCE _instanceHandle,
	_In_opt_ HINSTANCE _prevInstanceHandle,
	_In_ LPSTR _cmdLineStr,
	_In_ int _cmdShowNum)
{
	CANDY_UNUSED_VALUE(_instanceHandle);
	CANDY_UNUSED_VALUE(_prevInstanceHandle);
	CANDY_UNUSED_VALUE(_cmdLineStr);
	CANDY_UNUSED_VALUE(_cmdShowNum);

	Hardware::Cleanup();
}

CANDY_CORE_NAMESPACE_END
