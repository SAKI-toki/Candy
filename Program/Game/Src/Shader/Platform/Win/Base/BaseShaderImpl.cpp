/*****************************************************************//**
 * \file   BaseShaderImpl.cpp
 * \brief  �V�F�[�_�[�̃x�[�X�̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "BaseShaderImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Shader
{
	// ������
	void BaseShaderImpl::startup(std::byte* const _buf, const u64 _size)
	{
		m_Shader.pShaderBytecode = _buf;
		m_Shader.BytecodeLength = _size;
	}

	// �j��
	void BaseShaderImpl::cleanup()
	{
		m_Shader.pShaderBytecode = nullptr;
		m_Shader.BytecodeLength = 0;
	}
}

CANDY_NAMESPACE_END
