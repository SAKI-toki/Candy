/*****************************************************************//**
 * \file   GraphicShader.h
 * \brief  シェーダー
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_GRAPHIC_SHADER_H
#define CANDY_GRAPHIC_SHADER_H

#include <Graphic/GraphicInclude.h>

#include "Vertex/GraphicVertexShader.h"
#include "Pixel/GraphicPixelShader.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

enum class SHADER_TYPE
{
	PRIMITIVE_2D,
	FONT_FONT,
	TEST,
	TEST_MASK,
	TO_BACK_BUFFER,

#if BUILD_DEBUG
	DEBUG_STRING,
	DEBUG_PRIMITIVE_2D,
#endif // BUILD_DEBUG

	SIZE,
};
inline constexpr const char* const ShaderFileNames[] =
{
	"Primitive/2D",
	"Font/Font",
	"Test",
	"TestMask",
	"ToBackBuffer",

#if BUILD_DEBUG
	"Debug/String",
	"Debug/Primitive2D",
#endif // BUILD_DEBUG
};
static_assert((s32)SHADER_TYPE::SIZE == core::GetArraySize(ShaderFileNames));

namespace ShaderManager
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();

	// バーテックスシェーダーの取得
	const VertexShader& GetVertexShader(const SHADER_TYPE _shaderType);
	// ピクセルシェーダーの取得
	const PixelShader& GetPixelShader(const SHADER_TYPE _shaderType);
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_SHADER_H
