/*****************************************************************//**
 * \file   InputMouse.h
 * \brief  マウス入力
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_INPUT_MOUSE_H
#define CANDY_CORE_INPUT_MOUSE_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Input/Mouse/InputMouseImpl.h>
#endif // PLATFORM_WIN

CANDY_CORE_NAMESPACE_BEGIN

namespace Input
{
	class Mouse : public Impl::MouseImpl
	{
	public:
		// 初期化
		void startup();
		// 破棄
		void cleanup();
		// 更新
		void update();

		// リセット
		void reset();

		// PC画面上の位置取得
		Vec4 getScreenPos()const;
		// アプリ画面上の位置取得
		Vec4 getClientPos()const;
		// PC画面上の1フレ前位置取得
		Vec4 getPrevScreenPos()const;
		// アプリ画面上の1フレ前位置取得
		Vec4 getPrevClientPos()const;

	private:
		Vec4 m_ScreenPos{};
		Vec4 m_ClientPos{};
		Vec4 m_PrevScreenPos{};
		Vec4 m_PrevClientPos{};
	};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_INPUT_MOUSE_H
