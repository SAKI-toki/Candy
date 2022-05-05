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
		R8G8B8A8_UNORM,
		D32_FLOAT,
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

	struct ShaderRegisterType
	{
		s32 m_ShaderRegister;
		s32 m_RegisterSpace;
		SHADER_VISIBILITY_TYPE m_ShaderVisibilityType;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_TYPE_H
