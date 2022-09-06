﻿#include "GraphicBuffer.h"
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/SwapChain/GraphicSwapChain.h>
#include <Graphic/CommandList/GraphicCommandList.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

void Buffer::startup(const Device& _device, const BufferStartupInfo& _startupInfo)
{
	BufferImpl::startup(_device.getDevice(), _startupInfo);
}

void Buffer::startupBackBuffer(const SwapChain& _swapChain, const s32 _backBufferIndex)
{
	BufferImpl::startupBackBuffer(_swapChain.getSwapChain(), _backBufferIndex);
}

void Buffer::cleanup()
{
	BufferImpl::cleanup();
}

void Buffer::translationBarrier(const CommandList& _commandList, 
	const types::BARRIER_STATE _prevBarrierState, const types::BARRIER_STATE _nextBarrierState)
{
	BufferImpl::translationBarrier(_commandList.getCommandList(), _prevBarrierState, _nextBarrierState);
}

void Buffer::store(const std::byte* const _buf, const u64 _size, const u64 _offset)
{
	BufferImpl::store(_buf, _size, _offset);
}

void Buffer::setName(const std::string_view _name)
{
	BufferImpl::setName(_name);
}

CANDY_GRAPHIC_NAMESPACE_END
