/*****************************************************************//**
 * \file   Rect.inl
 * \brief  矩形
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#include "Rect.h"

CANDY_NAMESPACE_BEGIN

// コンストラクタ
inline Rect::Rect()
{
	setSize(0.0f, 0.0f, 0.0f, 0.0f);
}
inline Rect::Rect(const f32 _x, const f32 _y, const f32 _width, const f32 _height)
{
	setSize(_x, _y, _width, _height);
}

// サイズ基準のセット
inline Rect& Rect::setSize(const f32 _x, const f32 _y, const f32 _width, const f32 _height)
{
	m_X = _x;
	m_Y = _y;
	m_Width = _width;
	m_Height = _height;

	return *this;
}
// 座標基準のセット
inline Rect& Rect::setPos(const f32 _left, const f32 _top, const f32 _right, const f32 _bottom)
{
	return setSize(_left, _top, _right - _left, _bottom - _top);
}

// 右座標の取得
inline f32 Rect::getRight()const
{
	return m_X + m_Width;
}
// 下座標の取得
inline f32 Rect::getBottom()const
{
	return m_Y + m_Height;
}


CANDY_NAMESPACE_END
