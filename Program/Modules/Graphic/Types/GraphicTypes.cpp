#include "GraphicTypes.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

u64 types::GetBppGraphicFormat(const types::GRAPHIC_FORMAT _graphicFormat)
{
	switch (_graphicFormat)
	{
	case types::GRAPHIC_FORMAT::UNKNOWN:			return 0;
	case types::GRAPHIC_FORMAT::R8G8B8A8_UNORM:		return 32;
	case types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT:	return 128;
	case types::GRAPHIC_FORMAT::R16_UINT:			return 16;
	case types::GRAPHIC_FORMAT::D32_FLOAT:			return 32;
	case types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT:	return 32;
	case types::GRAPHIC_FORMAT::R32_UINT:			return 32;
	case types::GRAPHIC_FORMAT::BC1_UNORM:			return 4;
	case types::GRAPHIC_FORMAT::BC1_UNORM_SRGB:		return 4;
	case types::GRAPHIC_FORMAT::BC3_UNORM:			return 8;
	case types::GRAPHIC_FORMAT::BC3_UNORM_SRGB:		return 8;
	}

	CANDY_LOG("未設定のグラフィックフォーマットです");
	return 0;
}

CANDY_GRAPHIC_NAMESPACE_END
