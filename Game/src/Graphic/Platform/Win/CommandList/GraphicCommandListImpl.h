#ifndef CANDY_GRAPHIC_COMMAND_LIST_IMPL_H
#define CANDY_GRAPHIC_COMMAND_LIST_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class CommandListImpl
	{
	public:
		void startup(ID3D12Device* const _device, const COMMAND_LIST_TYPE _commandListType, const s32 _backBufferCount);
		void cleanup();

		void drawBegin(const s32 _frameNo);

		void close();

		ID3D12GraphicsCommandList* getCommandList()const { return m_CommandList.Get(); }

	private:
		std::vector<ComPtr<ID3D12CommandAllocator>> m_CommandAllocators;
		ComPtr<ID3D12GraphicsCommandList> m_CommandList;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_LIST_IMPL_H
