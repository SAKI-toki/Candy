#include "GraphicCommandListImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void CommandListImpl::startup(ID3D12Device* const _device, const COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount)
	{
		const auto CommandListType = ConvCommandListType(_commandListType);
		
		m_CommandAllocators.clear();
		m_CommandAllocators.resize(_backBufferCount);
		for (s32 i = 0; i < _backBufferCount; ++i)
		{
			CANDY_ASSERT_HRESULT(_device->CreateCommandAllocator(CommandListType,
				IID_PPV_ARGS(m_CommandAllocators[i].GetAddressOf())));
		}
		CANDY_ASSERT_HRESULT(_device->CreateCommandList(0, CommandListType, 
			m_CommandAllocators[0].Get(), nullptr, IID_PPV_ARGS(m_CommandList.GetAddressOf())));
	}

	void CommandListImpl::cleanup()
	{
		m_CommandList.Reset();
		for (auto& commandAllocator : m_CommandAllocators)commandAllocator.Reset();
		m_CommandAllocators.clear();
	}

	void CommandListImpl::drawBegin(const s32 _backBufferIndex)
	{
		CANDY_ASSERT_HRESULT(m_CommandList->Reset(m_CommandAllocators[_backBufferIndex].Get(), nullptr));
	}

	void CommandListImpl::close()
	{
		CANDY_ASSERT_HRESULT(m_CommandList->Close());
	}
}

CANDY_NAMESPACE_END
