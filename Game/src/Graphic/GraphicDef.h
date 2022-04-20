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

	s32 GetFrameCount();

	s32 GetScreenWidth();
	s32 GetScreenHeight();
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEF_H
