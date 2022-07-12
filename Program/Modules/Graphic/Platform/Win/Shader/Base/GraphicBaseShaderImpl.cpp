/*****************************************************************//**
 * \file   GraphicBaseShaderImpl.cpp
 * \brief  シェーダーのベースの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "GraphicBaseShaderImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

// 初期化
void BaseShaderImpl::startup(std::byte* const _buf, const u64 _size)
{
	m_Shader.pShaderBytecode = _buf;
	m_Shader.BytecodeLength = _size;
}

// 破棄
void BaseShaderImpl::cleanup()
{
	m_Shader.pShaderBytecode = nullptr;
	m_Shader.BytecodeLength = 0;
}

CANDY_GRAPHIC_NAMESPACE_END
