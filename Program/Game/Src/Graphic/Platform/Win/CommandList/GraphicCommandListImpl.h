#ifndef CANDY_GRAPHIC_COMMAND_LIST_IMPL_H
#define CANDY_GRAPHIC_COMMAND_LIST_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class CommandListImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount);
		void cleanup();

		void drawBegin(const s32 _frameNo);

		void close();

		void setViewport(const D3D12_VIEWPORT* const  _viewport);
		void setScissorRect(const D3D12_RECT* const  _scissorRect);

		void setRenderTargets(const D3D12_CPU_DESCRIPTOR_HANDLE* const _rtDescriptorCpuHandle,
			const s32 _renderTargetCount, const D3D12_CPU_DESCRIPTOR_HANDLE* const _dsDescriptorCpuHandle);
		void clearRenderTarget(const D3D12_CPU_DESCRIPTOR_HANDLE& _rtDescriptorCpuHandle, const Vec4 _color);

		void setRootSignature(ID3D12RootSignature* const _rootSignature);
		void setPipeline(ID3D12PipelineState* const _pipeline);

	public:
		ID3D12GraphicsCommandList* getCommandList()const { return m_CommandList.Get(); }

	private:
		std::vector<ComPtr<ID3D12CommandAllocator>> m_CommandAllocators;
		ComPtr<ID3D12GraphicsCommandList> m_CommandList;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_LIST_IMPL_H
