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
		R8G8B8A8_TYPELESS,
		R32G32B32A32_FLOAT,
		R16_UINT,
		D32_FLOAT,
		D24_UNORM_S8_UINT,
		R32_UINT,
		BC1_UNORM,
		BC1_UNORM_SRGB,
		BC3_UNORM,
		BC3_UNORM_SRGB,
	};

	enum class BARRIER_STATE
	{
		COMMON,
		RENDER_TARGET,
		PRESENT,
		PIXEL_SHADER_RESOURCE,
		CONSTANT_BUFFER,
		COPY_DEST,
		COPY_SOURCE,
	};

	enum class DESCRIPTOR_TYPE
	{
		CONSTANT_BUFFER,
		SHADER_RESOURCE,
		UNORDERED_ACCESS,
		RENDER_TARGET,
		DEPTH_STENCIL,
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

	enum class TEXTURE_ADDRESS_MODE
	{
		WRAP,
		CLAMP,
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

	enum class PRIMITIVE_TOPOLOGY_TYPE
	{
		TRIANGLE_LIST,
		TRIANGLE_STRIP,
	};

	enum class FILL_MODE
	{
		SOLID,
		WIREFRAME,
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
