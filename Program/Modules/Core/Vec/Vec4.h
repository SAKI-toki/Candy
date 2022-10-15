/*****************************************************************//**
 * \file   Vec4.h
 * \brief  Vector4
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_VEC4_H
#define CANDY_CORE_VEC4_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Vec/Vec4Impl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

struct Vec4 : core::Vec4Impl
{
	using Vec4Impl::Vec4Impl;

	Vec4();
	Vec4& operator=(const Vec4& _other);
	Vec4(const Vec4& _other);
	Vec4& operator=(Vec4&& _other)noexcept;
	Vec4(Vec4&& _other)noexcept;
	Vec4(const f32 _x, const f32 _y, const f32 _z, const f32 _w = 1.0f);

	Vec4& set(const f32 _x, const f32 _y, const f32 _z, const f32 _w = 1.0f);
	Vec4& setZero();

	Vec4 getXY()const;

	Vec4 operator+(const Vec4&)const;
	Vec4 operator-(const Vec4&)const;
	Vec4 operator*(const Vec4&)const;
	Vec4 operator/(const Vec4&)const;
	Vec4 operator*(const f32&)const;
	Vec4 operator/(const f32&)const;
	Vec4& operator+=(const Vec4&);
	Vec4& operator-=(const Vec4&);
	Vec4& operator*=(const f32&);
	Vec4& operator/=(const f32&);

	bool operator==(const Vec4&)const;
	bool operator!=(const Vec4&)const;
};

inline const Vec4 ZeroVector	= Vec4{  0.0f,  0.0f,  0.0f };
inline const Vec4 OneVector		= Vec4{  1.0f,  1.0f,  1.0f };
inline const Vec4 RightVector	= Vec4{  1.0f,  0.0f,  0.0f };
inline const Vec4 LeftVector	= Vec4{ -1.0f,  0.0f,  0.0f };
inline const Vec4 UpVector		= Vec4{  0.0f,  1.0f,  0.0f };
inline const Vec4 DownVector	= Vec4{  0.0f, -1.0f,  0.0f };
inline const Vec4 FrontVector	= Vec4{  0.0f,  0.0f,  1.0f };
inline const Vec4 BackVector	= Vec4{  0.0f,  0.0f, -1.0f };

CANDY_NAMESPACE_END

#endif // CANDY_CORE_VEC4_H
