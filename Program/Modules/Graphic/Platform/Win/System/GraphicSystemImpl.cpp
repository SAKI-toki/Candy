#include <Graphic/Platform/Win/System/GraphicSystemImpl.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	s32 m_DescriptorHandleIncrementSizes[D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES]{};
}

void impl::Startup(ID3D12Device* const _device)
{
	for (s32 i = 0; i < D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES; ++i)
	{
		m_DescriptorHandleIncrementSizes[i] = _device->GetDescriptorHandleIncrementSize(static_cast<D3D12_DESCRIPTOR_HEAP_TYPE>(i));
	}
}

s32 impl::GetDesciptorHandleIncrementSize(const D3D12_DESCRIPTOR_HEAP_TYPE _descriptorType)
{
	return m_DescriptorHandleIncrementSizes[static_cast<s32>(_descriptorType)];
}

CANDY_GRAPHIC_NAMESPACE_END
