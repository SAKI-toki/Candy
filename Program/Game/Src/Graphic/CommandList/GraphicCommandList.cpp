#include "GraphicCommandList.h"
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/Viewport/GraphicViewport.h>
#include <Graphic/ScissorRect/GraphicScissorRect.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/Pipeline/GraphicPipeline.h>
#include <Graphic/Buffer/GraphicBuffer.h>

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

	void CommandList::setRootSignature(const RootSignature& _rootSignature)
	{
		CommandListImpl::setRootSignature(_rootSignature.getRootSignature());
	}

	void CommandList::setPipeline(const Pipeline& _pipeline)
	{
		CommandListImpl::setPipeline(_pipeline.getPipeline());
	}

	void CommandList::setPrimitiveTopology(const PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType)
	{
		CommandListImpl::setPrimitiveTopology(_primitiveTopologyType);
	}

	void CommandList::setVertexBuffers(const VertexBufferView& _vertexBufferView)
	{
		CommandListImpl::setVertexBuffers(_vertexBufferView.getVertexBufferViewAddress());
	}

	void CommandList::setIndexBuffer(const IndexBufferView& _indexBufferView)
	{
		CommandListImpl::setIndexBuffer(_indexBufferView.getIndexBufferViewAddress());
	}

	void CommandList::setDescriptor(const Descriptor& _descriptor)
	{
		CommandListImpl::setDescriptor(_descriptor.getDescriptor());
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
	}
}

CANDY_NAMESPACE_END
