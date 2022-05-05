#include "BaseShader.h"
#include <FileSystem/FileSystem.h>

CANDY_NAMESPACE_BEGIN

namespace Shader
{
	void BaseShader::startup(std::byte* const _buf, const u64 _size)
	{
		BaseShaderImpl::startup(_buf, _size);
	}

	void BaseShader::cleanup()
	{
		BaseShaderImpl::cleanup();
	}
}

CANDY_NAMESPACE_END
