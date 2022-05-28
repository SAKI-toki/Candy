#ifndef CANDY_SHADER_H
#define CANDY_SHADER_H

#include "Vertex/VertexShader.h"
#include "Pixel/PixelShader.h"

CANDY_NAMESPACE_BEGIN

enum class SHADER_TYPE
{
	PRIMITIVE_2D,
	FONT_FONT,
	TEST,
	TEST_MASK,

#if BUILD_DEBUG
	DEBUG_STRING,
#endif // BUILD_DEBUG

	SIZE,
};
inline constexpr const char* const ShaderFileNames[] =
{
	"Primitive/2D",
	"Font/Font",
	"Test",
	"TestMask",

#if BUILD_DEBUG
	"Debug/String",
#endif // BUILD_DEBUG
};
static_assert((s32)SHADER_TYPE::SIZE == GetArraySize(ShaderFileNames));

namespace Shader
{
	void Startup();
	void Cleanup();

	const VertexShader& GetVertexShader(const SHADER_TYPE _shaderType);
	const PixelShader& GetPixelShader(const SHADER_TYPE _shaderType);
}

CANDY_NAMESPACE_END

#endif // CANDY_SHADER_H
