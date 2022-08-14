/*****************************************************************//**
 * \file   DebugDraw.h
 * \brief  デバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_PHYSICS_SHAPE_LINE_INL
#define CANDY_PHYSICS_SHAPE_LINE_INL

#include "DebugDraw.h"

CANDY_APP_NAMESPACE_BEGIN

// 文字列登録
template<typename ...Types>
inline void DebugDraw::DrawString(
	CANDY_UNUSED_VALUE_ATTR const String::AddInfo& _addInfo, 
	CANDY_UNUSED_VALUE_ATTR const std::string_view _format,
	CANDY_UNUSED_VALUE_ATTR Types&& ..._args)
{
#if BUILD_DEBUG
	String::Add(_addInfo, std::format(_format, std::forward<Types>(_args)...));
#endif // BUILD_DEBUG
}

// 文字列登録(フォーマット、位置)
template<typename ...Types>
inline void DebugDraw::DrawString(
	CANDY_UNUSED_VALUE_ATTR const Vec4 _pos, 
	CANDY_UNUSED_VALUE_ATTR const std::string_view _format,
	CANDY_UNUSED_VALUE_ATTR Types&& ..._args)
{
#if BUILD_DEBUG
	String::AddInfo addInfo{};
	addInfo.m_Pos = _pos;
	String::Add(addInfo, std::format(_format, std::forward<Types>(_args)...));
#endif // BUILD_DEBUG
}

// 文字列登録(フォーマット、位置, 色)
template<typename ...Types>
inline void DebugDraw::DrawString(
	CANDY_UNUSED_VALUE_ATTR const Vec4 _pos, 
	CANDY_UNUSED_VALUE_ATTR const Color _color,
	CANDY_UNUSED_VALUE_ATTR const std::string_view _format,
	CANDY_UNUSED_VALUE_ATTR Types&& ..._args)
{
#if BUILD_DEBUG
	String::AddInfo addInfo{};
	addInfo.m_Pos = _pos;
	addInfo.m_Color = _color;
	String::Add(addInfo, std::format(_format, std::forward<Types>(_args)...));
#endif // BUILD_DEBUG
}

// 文字列登録(フォーマット、位置, 色, サイズ)
template<typename ...Types>
inline void DebugDraw::DrawString(
	CANDY_UNUSED_VALUE_ATTR const Vec4 _pos,
	CANDY_UNUSED_VALUE_ATTR const Color _color, const f32 _scale,
	CANDY_UNUSED_VALUE_ATTR const std::string_view _format,
	CANDY_UNUSED_VALUE_ATTR Types&& ..._args)
{
#if BUILD_DEBUG
	String::AddInfo addInfo{};
	addInfo.m_Pos = _pos;
	addInfo.m_Color = _color;
	addInfo.m_Scale = _scale;
	String::Add(addInfo, std::format(_format, std::forward<Types>(_args)...));
#endif // BUILD_DEBUG
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_PHYSICS_SHAPE_LINE_INL
