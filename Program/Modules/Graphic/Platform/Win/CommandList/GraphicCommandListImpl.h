#ifndef CANDY_GRAPHIC_COMMAND_LIST_IMPL_H
#define CANDY_GRAPHIC_COMMAND_LIST_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class CommandListImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const types::COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount);
		void cleanup();

		void preDraw(const s32 _frameNo);

		void close();

		void setViewport(const D3D12_VIEWPORT* const  _viewport);
		void setScissorRect(const D3D12_RECT* const  _scissorRect);

		void setRenderTargets(const D3D12_CPU_DESCRIPTOR_HANDLE* const _rtDescriptorCpuHandle,
			const s32 _renderTargetCount, const D3D12_CPU_DESCRIPTOR_HANDLE* const _dsDescriptorCpuHandle);
		void clearRenderTarget(const D3D12_CPU_DESCRIPTOR_HANDLE& _rtDescriptorCpuHandle, const Vec4 _color);
		void clearDepthStencil(const D3D12_CPU_DESCRIPTOR_HANDLE& _dsDescriptorCpuHandle,
			const bool _clearDepth, const f32 _depth, const bool _clearStencil, const u32 _stencil);

		void setRootSignature(ID3D12RootSignature* const _rootSignature);
		void setPipeline(ID3D12PipelineState* const _pipeline);

		void setPrimitiveTopology(const types::PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType);
		void setVertexBuffer(const s32 _index, const D3D12_VERTEX_BUFFER_VIEW& _vertexBufferView);
		void registVertexBuffers(const s32 _count);
		void setIndexBuffer(const D3D12_INDEX_BUFFER_VIEW* const  _indexBufferView);

		void setDescriptor(const s32 _index, ID3D12DescriptorHeap* const _descriptor);
		void registDescriptors(const s32 _count, const s32 _offsetIndex);
		void setDescriptorTable(const s32 _rootParameterIndex, const D3D12_GPU_DESCRIPTOR_HANDLE& _descriptorCpuHandle);

		void drawIndexedInstanced(const u32 _indexCountPerInstance, const u32 _instanceCount,
			const u32 _startIndexLocation, const u32 _baseVertexLocation, const u32 _startInstanceLocation);

		void copyTexture(ID3D12Device* const _device, ID3D12Resource* const _dstBuffer, ID3D12Resource* const _srcBuffer);

	public:
		ID3D12GraphicsCommandList* getCommandList()const { return m_CommandList.Get(); }

	private:
		std::vector<core::ComPtr<ID3D12CommandAllocator>> m_CommandAllocators;
		core::ComPtr<ID3D12GraphicsCommandList> m_CommandList;

		D3D12_VERTEX_BUFFER_VIEW m_VertexBufferViews[32]{};
		ID3D12DescriptorHeap* m_DescriptorHeaps[32]{};
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_LIST_IMPL_H
