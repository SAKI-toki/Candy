/*****************************************************************//**
 * \file   BaseShader.h
 * \brief  シェーダーのベース
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_BASE_SHADER_H
#define CANDY_BASE_SHADER_H

#if PLATFORM_WIN
#include <Shader/Platform/Win/Base/BaseShaderImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Shader
{
	class BaseShader : public BaseShaderImpl
	{
	public:
		// 初期化
		void startup(std::byte* const _buf, const u64 _size);
		// 破棄
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_BASE_SHADER_H
