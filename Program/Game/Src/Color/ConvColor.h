#ifndef CANDY_CONV_COLOR_H
#define CANDY_CONV_COLOR_H

#include "Color.h"

CANDY_NAMESPACE_BEGIN

#define CANDY_COLOR_RGBA32(r, g, b, a) (Vec4{ \
	static_cast<f32>(r) / 255.0f, \
	static_cast<f32>(g) / 255.0f, \
	static_cast<f32>(b) / 255.0f, \
	static_cast<f32>(a) / 255.0f })

#define CANDY_COLOR_RGB32(r, g, b) (Vec4{ \
	static_cast<f32>(r) / 255.0f, \
	static_cast<f32>(g) / 255.0f, \
	static_cast<f32>(b) / 255.0f, \
	1.0f })

CANDY_NAMESPACE_END

#endif // CANDY_CONV_COLOR_H
