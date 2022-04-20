#include "GraphicCommandListImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void CommandListImpl::startup(ID3D12Device* const _device, const COMMAND_LIST_TYPE _commandListType)
	{
		const auto CommandListType = ConvCommandListType(_commandListType);
		
		CANDY_ASSERT_HRESULT(_device->CreateCommandAllocator(CommandListType,
			IID_PPV_ARGS(m_CommandAllocator.GetAddressOf())));
		CANDY_ASSERT_HRESULT(_device->CreateCommandList(0, CommandListType, 
			m_CommandAllocator.Get(), nullptr, IID_PPV_ARGS(m_CommandList.GetAddressOf())));
	}

	void CommandListImpl::cleanup()
	{
		m_CommandList.Reset();
		m_CommandAllocator.Reset();
	}
}

CANDY_NAMESPACE_END
