#ifndef CANDY_GRAPHIC_TYPE_H
#define CANDY_GRAPHIC_TYPE_H

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	enum class COMMAND_LIST_TYPE
	{
		RENDERING,
		COMPUTE,
	};

	enum class GRAPHIC_FORMAT
	{
		UNKNOWN,
		R8G8B8A8_UNORM,
		R32G32B32A32_FLOAT,
		D32_FLOAT,
		R32_UINT,
	};

	enum class BARRIER_STATE
	{
		COMMON,
		RENDER_TARGET,
		PRESENT,
	};

	enum class DESCRIPTOR_TYPE
	{
		CONSTANT_BUFFER,
		SHADER_RESOURCE,
		UNORDERED_ACCESS,
		RENDER_TARGET,
	};

	enum class SHADER_SEMANTIC_TYPE
	{
		POSITION,
		TEXCOORD,
		COLOR,
		NORMAL,
		BINORMAL,
		TANGENT,
		BLENDINDICES,
		BLENDWEIGHT,
	};

	enum class FILTER_TYPE
	{
		ANISOTROPIC,
	};

	enum class SHADER_VISIBILITY_TYPE
	{
		VERTEX,
		PIXEL,
		ALL,
	};

	enum class COMPARISON_TYPE
	{
		NEVER,
		LESS,
		EQUAL,
		LESS_EQUAL,
		GREATER,
		NOT_EQUAL,
		GREATER_EQUAL,
		ALWAYS,
	};

	enum class ROOT_SIGNATURE_FLAG
	{
		NONE,
		ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT,
	};

	struct ShaderRegisterInfo
	{
		ShaderRegisterInfo() = default;
		ShaderRegisterInfo(const s32 _shaderRegister, const s32 _registerSpace, const SHADER_VISIBILITY_TYPE _shaderVisibilityType) :
			m_ShaderRegister{ _shaderRegister },
			m_RegisterSpace{ _registerSpace },
			m_ShaderVisibilityType{ _shaderVisibilityType }
		{

		}

		s32 m_ShaderRegister{ 0 };
		s32 m_RegisterSpace{ 0 };
		SHADER_VISIBILITY_TYPE m_ShaderVisibilityType{ SHADER_VISIBILITY_TYPE::ALL };
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_TYPE_H
