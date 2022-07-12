/*****************************************************************//**
 * \file   HardwareImpl.cpp
 * \brief  ハードウェアの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "HardwareImpl.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace Hardware::Impl
{
	// ウィンドウプロシージャ
	LRESULT CALLBACK WndProc(HWND _hwnd, UINT _message, WPARAM _wparam, LPARAM _lparam);
	HWND m_Hwnd;
	bool m_IsClose = false;
}

// 初期化
void Hardware::Impl::Startup(const StartupInfo& _startupInfo)
{
	WNDCLASSEX wndClass{};
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hInstance = _startupInfo.m_InstanceHandle;
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndClass.lpszClassName = _startupInfo.m_Name.c_str();
	RegisterClassEx(&wndClass);

	RECT rect{ 0, 0, static_cast<LONG>(_startupInfo.m_Width), static_cast<LONG>(_startupInfo.m_Height) };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);

	m_Hwnd = CreateWindow(
		wndClass.lpszClassName, wndClass.lpszClassName,
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		rect.right - rect.left, rect.bottom - rect.top,
		nullptr, nullptr, _startupInfo.m_InstanceHandle, nullptr);

	::ShowWindow(m_Hwnd, _startupInfo.m_CmdShowNum);
	::UpdateWindow(m_Hwnd);
}

// 破棄
void Hardware::Impl::Cleanup()
{

}

// 更新
void Hardware::Impl::Update()
{
	MSG msg{ 0 };
	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	if (msg.message == WM_QUIT)m_IsClose = true;
}

// 閉じたか
bool Hardware::Impl::IsClose()
{
	return m_IsClose;
}

// ウィンドウハンドラの取得
WindowHandle Hardware::Impl::GetHwnd()
{
	return m_Hwnd;
}

// ウィンドウプロシージャ
LRESULT CALLBACK Hardware::Impl::WndProc(HWND _hwnd, UINT _message, WPARAM _wparam, LPARAM _lparam)
{
	switch (_message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
	}
	return 0;
	}

	return DefWindowProc(_hwnd, _message, _wparam, _lparam);
}

CANDY_CORE_NAMESPACE_END
