#include "MainImpl.h"
#include <Hardware/Hardware.h>

CANDY_NAMESPACE_BEGIN

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
	hardwareStartupInfo.m_Name = Setting::GetAppName();
	hardwareStartupInfo.m_Width = 1600;
	hardwareStartupInfo.m_Height = 900;
	Hardware::Startup(hardwareStartupInfo);
}

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

CANDY_NAMESPACE_END
