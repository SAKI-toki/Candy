/*****************************************************************//**
 * \file   GraphicBaseShaderImpl.h
 * \brief  シェーダーのベースの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_GRAPHIC_BASE_SHADER_IMPL_H
#define CANDY_GRAPHIC_BASE_SHADER_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

class BaseShaderImpl
{
protected:
	// 初期化
	void startup(std::byte* const _buf, const u64 _size);
	// 破棄
	void cleanup();

public:
	// シェーダー取得
	D3D12_SHADER_BYTECODE getShader()const { return m_Shader; }

private:
	D3D12_SHADER_BYTECODE m_Shader;
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_BASE_SHADER_IMPL_H
