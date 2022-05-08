#include "GraphicCommandQueueImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	void CommandQueueImpl::startup(ID3D12Device* const _device, const COMMAND_LIST_TYPE _commandListType)
	{
		D3D12_COMMAND_QUEUE_DESC desc{};
		desc.Type = ConvCommandListType(_commandListType);

		CANDY_ASSERT_HRESULT(_device->CreateCommandQueue(&desc, IID_PPV_ARGS(m_CommandQueue.GetAddressOf())));
	}

	void CommandQueueImpl::cleanup()
	{
		m_CommandQueue.Reset();
	}

	void CommandQueueImpl::executeCommandList(ID3D12CommandList* const _commandList)const
	{
		m_CommandQueue->ExecuteCommandLists(1, &_commandList);
	}
}

CANDY_NAMESPACE_END
