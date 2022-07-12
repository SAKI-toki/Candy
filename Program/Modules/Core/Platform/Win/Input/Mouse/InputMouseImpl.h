/*****************************************************************//**
 * \file   InputMouseImpl.h
 * \brief  マウス入力の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#ifndef CANDY_CORE_INPUT_MOUSE_IMPL_H
#define CANDY_CORE_INPUT_MOUSE_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Input::Impl
{
	class MouseImpl
	{
	protected:
		// PC画面上の位置取得
		Vec4 getScreenPos()const;
		// PC画面上の位置からアプリ画面上の位置に変換
		Vec4 toClientPos(const Vec4 _screenPos)const;
	};
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_INPUT_MOUSE_IMPL_H
