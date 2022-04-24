#ifndef CANDY_GRAPHIC_IMPL_H
#define CANDY_GRAPHIC_IMPL_H

#include "GraphicDefWin.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	void preCalc(ID3D12Device* const _device);

	s32 GetDesciptorHandleIncrementSize(const D3D12_DESCRIPTOR_HEAP_TYPE _descriptorType);
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_IMPL_H
