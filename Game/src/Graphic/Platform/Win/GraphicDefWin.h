#ifndef CANDY_GRAPHIC_DEF_WIN_H
#define CANDY_GRAPHIC_DEF_WIN_H

#include <Graphic/GraphicDef.h>

CANDY_NAMESPACE_BEGIN

#define CANDY_ASSERT_HRESULT(EXPR) CANDY_ASSERT(SUCCEEDED(EXPR))

namespace Graphic
{
	D3D12_COMMAND_LIST_TYPE ConvCommandListType(const COMMAND_LIST_TYPE _commandListType);
	DXGI_FORMAT ConvTextureFormat(const TEXTURE_FORMAT _textureFormat);
	D3D12_RESOURCE_STATES ConvBarrierState(const BARRIER_STATE _barrierState);
	D3D12_DESCRIPTOR_HEAP_TYPE ConvDescriptorType(const DESCRIPTOR_TYPE _descriptorType);

	s32 GetDesciptorHandleIncrementSize(const D3D12_DESCRIPTOR_HEAP_TYPE _descriptorType);
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEF_WIN_H
