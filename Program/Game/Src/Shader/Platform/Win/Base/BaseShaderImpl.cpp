#include "BaseShaderImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Shader
{
	void BaseShaderImpl::startup(std::byte* const _buf, const u64 _size)
	{
		m_Shader.pShaderBytecode = _buf;
		m_Shader.BytecodeLength = _size;
	}

	void BaseShaderImpl::cleanup()
	{
		m_Shader.pShaderBytecode = nullptr;
		m_Shader.BytecodeLength = 0;
	}
}

CANDY_NAMESPACE_END
