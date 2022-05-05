#ifndef CANDY_BASE_SHADER_IMPL_H
#define CANDY_BASE_SHADER_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Shader
{
	class BaseShaderImpl
	{
	protected:
		void startup(std::byte* const _buf, const u64 _size);
		void cleanup();

	public:
		D3D12_SHADER_BYTECODE getShader()const { return m_Shader; }

	private:
		D3D12_SHADER_BYTECODE m_Shader;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_BASE_SHADER_IMPL_H
