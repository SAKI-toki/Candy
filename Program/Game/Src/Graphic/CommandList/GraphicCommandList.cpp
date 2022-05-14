#include "GraphicCommandList.h"
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/Viewport/GraphicViewport.h>
#include <Graphic/ScissorRect/GraphicScissorRect.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/Pipeline/GraphicPipeline.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/ResourceManager/GraphicResourceManager.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void CommandList::startup(const Device& _device, const COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount)
	{
		CommandListImpl::startup(_device.getDevice(), _commandListType, _backBufferCount);
	}

	void CommandList::cleanup()
	{
		CommandListImpl::cleanup();
	}

	void CommandList::preDraw(const s32 _backBufferIndex)
	{
		CommandListImpl::preDraw(_backBufferIndex);
	}

	void CommandList::close()
	{
		CommandListImpl::close();
	}

	void CommandList::setViewport(const Viewport& _viewport)
	{
		CommandListImpl::setViewport(_viewport.getViewport());
	}

	void CommandList::setScissorRect(const ScissorRect& _scissorRect)
	{
		CommandListImpl::setScissorRect(_scissorRect.getScissorRect());
	}

	void CommandList::setRenderTargets(const DescriptorCpuHandle& _rtDescriptorCpuHandle, const s32 _renderTargetCount)
	{
		CommandListImpl::setRenderTargets(_rtDescriptorCpuHandle.getHandleAddress(), _renderTargetCount, nullptr);
	}

	void CommandList::setDepthStencil(const DescriptorCpuHandle& _dsDescriptorCpuHandle)
	{
		CommandListImpl::setRenderTargets(nullptr, 0, _dsDescriptorCpuHandle.getHandleAddress());
	}

	void CommandList::setRenderTargetsDepthStencil(const DescriptorCpuHandle& _rtDescriptorCpuHandle,
		const s32 _renderTargetCount, const DescriptorCpuHandle& _dsDescriptorCpuHandle)
	{
		CommandListImpl::setRenderTargets(_rtDescriptorCpuHandle.getHandleAddress(),
			_renderTargetCount, _dsDescriptorCpuHandle.getHandleAddress());
	}

	void CommandList::clearRenderTarget(const DescriptorCpuHandle& _rtDescriptorCpuHandle, const Vec4 _color)
	{
		CommandListImpl::clearRenderTarget(_rtDescriptorCpuHandle.getHandle(), _color);
	}

	void CommandList::clearDepth(const DescriptorCpuHandle& _dsDescriptorCpuHandle, const f32 _depth)
	{
		CommandListImpl::clearDepthStencil(_dsDescriptorCpuHandle.getHandle(), true, _depth, false, 0);
	}

	void CommandList::clearStencil(const DescriptorCpuHandle& _dsDescriptorCpuHandle, const u32 _stencil)
	{
		CommandListImpl::clearDepthStencil(_dsDescriptorCpuHandle.getHandle(), false, 0.0f, true, _stencil);
	}

	void CommandList::clearDepthStencil(const DescriptorCpuHandle& _dsDescriptorCpuHandle, const f32 _depth, const u32 _stencil)
	{
		CommandListImpl::clearDepthStencil(_dsDescriptorCpuHandle.getHandle(), true, _depth, true, _stencil);
	}

	void CommandList::setRootSignature(const RootSignature& _rootSignature)
	{
		CommandListImpl::setRootSignature(_rootSignature.getRootSignature());
		ResourceManager::Regist(_rootSignature);
	}

	void CommandList::setPipeline(const Pipeline& _pipeline)
	{
		CommandListImpl::setPipeline(_pipeline.getPipeline());
		ResourceManager::Regist(_pipeline);
	}

	void CommandList::setPrimitiveTopology(const PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType)
	{
		CommandListImpl::setPrimitiveTopology(_primitiveTopologyType);
	}

	void CommandList::setVertexBuffer(const s32 _index, const VertexBufferView& _vertexBufferView)
	{
		CommandListImpl::setVertexBuffer(_index, _vertexBufferView.getVertexBufferView());
	}

	void CommandList::registVertexBuffers(const s32 _count)
	{
		CommandListImpl::registVertexBuffers(_count);
	}

	void CommandList::setIndexBuffer(const IndexBufferView& _indexBufferView)
	{
		CommandListImpl::setIndexBuffer(_indexBufferView.getIndexBufferViewAddress());
	}

	void CommandList::setDescriptor(const s32 _index, const Descriptor& _descriptor)
	{
		CommandListImpl::setDescriptor(_index, _descriptor.getDescriptor());
		ResourceManager::Regist(_descriptor);
	}

	void CommandList::registDescriptors(const s32 _count)
	{
		CommandListImpl::registDescriptors(_count);
	}

	void CommandList::setDescriptorTable(const s32 _rootParameterIndex, const Descriptor& _descriptor, const s32 _offsetIndex)
	{
		CommandListImpl::setDescriptorTable(_rootParameterIndex, _descriptor.getGpuHandle(_offsetIndex).getHandle());
	}

	void CommandList::drawIndexedInstanced(const u32 _indexCountPerInstance, const u32 _instanceCount,
		const u32 _startIndexLocation, const u32 _baseVertexLocation, const u32 _startInstanceLocation)
	{
		CommandListImpl::drawIndexedInstanced(_indexCountPerInstance, _instanceCount,
			_startIndexLocation, _baseVertexLocation, _startInstanceLocation);
	}

	void CommandList::copyTexture(const Device& _device, const Buffer& _dstBuffer, const Buffer& _srcBuffer)
	{
		CommandListImpl::copyTexture(_device.getDevice(), _dstBuffer.getBuffer(), _srcBuffer.getBuffer());
		ResourceManager::Regist(_dstBuffer);
		ResourceManager::Regist(_srcBuffer);
	}
}

CANDY_NAMESPACE_END
