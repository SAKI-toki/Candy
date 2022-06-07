/*****************************************************************//**
 * \file   DebugDraw.cpp
 * \brief  ÉfÉoÉbÉOï`âÊ
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "DebugDraw.h"
#include "String/DebugDrawString.h"
#include <Mutex/CriticalSection.h>

CANDY_NAMESPACE_BEGIN

namespace DebugDraw
{
#if BUILD_DEBUG
	CriticalSection m_CriticalSection;
#endif // BUILD_DEBUG
}

// èâä˙âª
void DebugDraw::Startup()
{
#if BUILD_DEBUG
	DebugDraw::String::Startup();
	m_CriticalSection.startup();
#endif // BUILD_DEBUG
}

// îjä¸
void DebugDraw::Cleanup()
{
#if BUILD_DEBUG
	m_CriticalSection.cleanup();
	DebugDraw::String::Cleanup();
#endif // BUILD_DEBUG
}

// çXêV
void DebugDraw::Update()
{
#if BUILD_DEBUG
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	DebugDraw::String::Update();
#endif // BUILD_DEBUG
}

// ï`âÊ
void DebugDraw::Draw()
{
#if BUILD_DEBUG
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	DebugDraw::String::Draw();
#endif // BUILD_DEBUG
}

// ï∂éöóÒìoò^(à íu)
void DebugDraw::DrawString(const Vec4 _pos, const char* const _format, ...)
{
#if BUILD_DEBUG
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
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

// ï∂éöóÒìoò^(à íu, êF)
void DebugDraw::DrawString(const Vec4 _pos, const Color _color, const char* const _format, ...)
{
#if BUILD_DEBUG
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
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

// ï∂éöóÒìoò^(à íu, êF, ÉTÉCÉY)
void DebugDraw::DrawString(const Vec4 _pos, const Color _color, const f32 _scale, const char* const _format, ...)
{
#if BUILD_DEBUG
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
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

CANDY_NAMESPACE_END
