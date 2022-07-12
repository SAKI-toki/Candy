/*****************************************************************//**
 * \file   Rect.h
 * \brief  矩形
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CORE_RECT_H
#define CANDY_CORE_RECT_H

#include <Core/CoreInclude.h>

CANDY_NAMESPACE_BEGIN

struct alignas(16) Rect
{
	// コンストラクタ
	Rect();
	Rect(const f32 _x, const f32 _y, const f32 _width, const f32 _height);

	// サイズ基準のセット
	Rect& setSize(const f32 _x, const f32 _y, const f32 _width, const f32 _height);
	// 座標基準のセット
	Rect& setPos(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom);

	// 右座標の取得
	f32 getRight()const;
	// 下座標の取得
	f32 getBottom()const;

	f32 m_X;
	f32 m_Y;
	f32 m_Width;
	f32 m_Height;
};

CANDY_NAMESPACE_END

#include "Rect.inl"

#endif // CANDY_CORE_RECT_H
