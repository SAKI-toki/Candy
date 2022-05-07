#ifndef CANDY_GRAPHIC_COMMAND_LIST_H
#define CANDY_GRAPHIC_COMMAND_LIST_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/CommandList/GraphicCommandListImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Device;
	class Viewport;
	class ScissorRect;
	class DescriptorCpuHandle;
	class RootSignature;
	class Pipeline;
	class VertexBufferView;
	class IndexBufferView;
	class Descriptor;

	class CommandList : public CommandListImpl
	{
	public:
		void startup(const Device& _device, const COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount);
		void cleanup();

		void drawBegin(const s32 _backBufferIndex);

		void close();

		void setViewport(const Viewport& _viewport);
		void setScissorRect(const ScissorRect& _scissorRect);

		void setRenderTargets(const DescriptorCpuHandle& _rtDescriptorCpuHandle, const s32 _renderTargetCount);
		void setRenderTargetsDepthStencil(const DescriptorCpuHandle& _rtDescriptorCpuHandle,
			const s32 _renderTargetCount, const DescriptorCpuHandle& _dsDescriptorCpuHandle);
		void clearRenderTarget(const DescriptorCpuHandle& _rtDescriptorCpuHandle, const Vec4 _color);

		void setRootSignature(const RootSignature& _rootSignature);
		void setPipeline(const Pipeline& _pipeline);

		void setPrimitiveTopology(const PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType);
		void setVertexBuffers(const VertexBufferView& _vertexBufferView);
		void setIndexBuffer(const IndexBufferView& _indexBufferView);

		void setDescriptor(const Descriptor& _descriptor);
		void setDescriptorTable(const s32 _rootParameterIndex, const Descriptor& _descriptor, const s32 _offsetIndex);

		void drawIndexedInstanced(const u32 _indexCountPerInstance, const u32 _instanceCount,
			const u32 _startIndexLocation, const u32 _baseVertexLocation, const u32 _startInstanceLocation);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_LIST_H
