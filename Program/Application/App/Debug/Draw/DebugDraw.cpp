/*****************************************************************//**
 * \file   DebugDraw.cpp
 * \brief  デバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "DebugDraw.h"
#include "String/DebugDrawString.h"

CANDY_APP_NAMESPACE_BEGIN

namespace DebugDraw
{

}

// 初期化
void DebugDraw::Startup()
{
#if BUILD_DEBUG
	DebugDraw::String::Startup();
#endif // BUILD_DEBUG
}

// 破棄
void DebugDraw::Cleanup()
{
#if BUILD_DEBUG
	DebugDraw::String::Cleanup();
#endif // BUILD_DEBUG
}

// 更新
void DebugDraw::Update()
{
#if BUILD_DEBUG
	DebugDraw::String::Update();
#endif // BUILD_DEBUG
}

// 描画
void DebugDraw::Draw()
{
#if BUILD_DEBUG
	DebugDraw::String::Draw();
#endif // BUILD_DEBUG
}

// 文字列登録(位置)
void DebugDraw::DrawString(const Vec4 _pos, const char* const _format, ...)
{
#if BUILD_DEBUG
	char str[2048];
	va_list vaList;
	va_start(vaList, _format);
	vsprintf_s(str, _format, vaList);
	String::Add(_pos, str);
	va_end(vaList);
#else // BUILD_DEBUG
	CANDY_UNUSED_VALUE(_pos);
	CANDY_UNUSED_VALUE(_format);
#endif // BUILD_DEBUG
}

// 文字列登録(位置, 色)
void DebugDraw::DrawString(const Vec4 _pos, const Color _color, const char* const _format, ...)
{
#if BUILD_DEBUG
	char str[2048];
	va_list vaList;
	va_start(vaList, _format);
	vsprintf_s(str, _format, vaList);
	String::Add(_pos, _color, str);
	va_end(vaList);
#else // BUILD_DEBUG
	CANDY_UNUSED_VALUE(_pos);
	CANDY_UNUSED_VALUE(_color);
	CANDY_UNUSED_VALUE(_format);
#endif // BUILD_DEBUG
}

// 文字列登録(位置, 色, サイズ)
void DebugDraw::DrawString(const Vec4 _pos, const Color _color, const f32 _scale, const char* const _format, ...)
{
#if BUILD_DEBUG
	char str[2048];
	va_list vaList;
	va_start(vaList, _format);
	vsprintf_s(str, _format, vaList);
	String::Add(_pos, _color, _scale, str);
	va_end(vaList);
#else // BUILD_DEBUG
	CANDY_UNUSED_VALUE(_pos);
	CANDY_UNUSED_VALUE(_color);
	CANDY_UNUSED_VALUE(_scale);
	CANDY_UNUSED_VALUE(_format);
#endif // BUILD_DEBUG
}

CANDY_APP_NAMESPACE_END
