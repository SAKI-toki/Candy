/*****************************************************************//**
 * \file   BaseShader.cpp
 * \brief  シェーダーのベース
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "BaseShader.h"
#include <FileSystem/FileSystem.h>

CANDY_NAMESPACE_BEGIN

namespace Shader
{
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
}

CANDY_NAMESPACE_END
