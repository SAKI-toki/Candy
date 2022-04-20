#ifndef CANDY_GRAPHIC_DEF_WIN_H
#define CANDY_GRAPHIC_DEF_WIN_H

#include <Graphic/GraphicDef.h>

CANDY_NAMESPACE_BEGIN

#define CANDY_ASSERT_HRESULT(EXPR) CANDY_ASSERT(SUCCEEDED(EXPR))

namespace Graphic
{
	D3D12_COMMAND_LIST_TYPE ConvCommandListType(const COMMAND_LIST_TYPE _commandListType);
	DXGI_FORMAT ConvTextureFormat(const TEXTURE_FORMAT _textureFormat);
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEF_WIN_H
