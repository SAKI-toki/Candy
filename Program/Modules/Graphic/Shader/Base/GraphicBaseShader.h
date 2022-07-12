/*****************************************************************//**
 * \file   GraphicBaseShader.h
 * \brief  シェーダーのベース
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_GRAPHIC_BASE_SHADER_H
#define CANDY_GRAPHIC_BASE_SHADER_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Shader/Base/GraphicBaseShaderImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class BaseShader : public BaseShaderImpl
{
public:
	// 初期化
	void startup(std::byte* const _buf, const u64 _size);
	// 破棄
	void cleanup();
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_BASE_SHADER_H
