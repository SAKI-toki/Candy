#ifndef CANDY_GRAPHIC_DEF_H
#define CANDY_GRAPHIC_DEF_H

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	enum class COMMAND_LIST_TYPE
	{
		RENDERING,
		COMPUTE,

		SIZE,
	};

	enum class TEXTURE_FORMAT
	{
		R8G8B8A8_UNORM,
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

	s32 GetBackBufferCount();

	s32 GetScreenWidth();
	s32 GetScreenHeight();
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEF_H
