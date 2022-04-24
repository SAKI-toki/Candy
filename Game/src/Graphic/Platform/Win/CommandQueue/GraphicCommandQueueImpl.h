#ifndef CANDY_GRAPHIC_COMMAND_QUEUE_IMPL_H
#define CANDY_GRAPHIC_COMMAND_QUEUE_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class CommandQueueImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const COMMAND_LIST_TYPE _commandListType);
		void cleanup();

		void executeCommandList(ID3D12CommandList* const _commandList);

	public:
		ID3D12CommandQueue* getCommandQueue()const { return m_CommandQueue.Get(); }

	private:
		ComPtr<ID3D12CommandQueue> m_CommandQueue;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_QUEUE_IMPL_H
