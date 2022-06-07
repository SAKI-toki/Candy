/*****************************************************************//**
 * \file   InputMouse.cpp
 * \brief  マウス入力
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "InputMouse.h"

CANDY_NAMESPACE_BEGIN

namespace Input
{
	// 初期化
	void Mouse::startup()
	{
		reset();
	}

	// 破棄
	void Mouse::cleanup()
	{

	}

	// 更新
	void Mouse::update()
	{
		m_PrevScreenPos = m_ScreenPos;
		m_PrevClientPos = m_ClientPos;

		m_ScreenPos = MouseImpl::getScreenPos();
		m_ClientPos = MouseImpl::toClientPos(m_ScreenPos);
	}

	// リセット
	void Mouse::reset()
	{
		m_ScreenPos = ZeroVector;
		m_ClientPos = ZeroVector;
		m_PrevScreenPos = ZeroVector;
		m_PrevClientPos = ZeroVector;
	}

	// PC画面上の位置取得
	Vec4 Mouse::getScreenPos()const		{ return m_ScreenPos; }
	// アプリ画面上の位置取得
	Vec4 Mouse::getClientPos()const		{ return m_ClientPos; }
	// PC画面上の1フレ前位置取得
	Vec4 Mouse::getPrevScreenPos()const { return m_PrevScreenPos; }
	// アプリ画面上の1フレ前位置取得
	Vec4 Mouse::getPrevClientPos()const { return m_PrevClientPos; }
}

CANDY_NAMESPACE_END
