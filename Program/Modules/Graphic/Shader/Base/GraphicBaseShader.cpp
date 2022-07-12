/*****************************************************************//**
 * \file   GraphicBaseShader.cpp
 * \brief  シェーダーのベース
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "GraphicBaseShader.h"
#include <Core/FileSystem/FileSystem.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

// 初期化
void BaseShader::startup(std::byte* const _buf, const u64 _size)
{
	BaseShaderImpl::startup(_buf, _size);
}

// 破棄
void BaseShader::cleanup()
{
	BaseShaderImpl::cleanup();
}

CANDY_GRAPHIC_NAMESPACE_END
