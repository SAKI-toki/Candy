#ifndef CANDY_GRAPHIC_COMMAND_QUEUE_IMPL_H
#define CANDY_GRAPHIC_COMMAND_QUEUE_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class CommandQueueImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const types::COMMAND_LIST_TYPE _commandListType);
		void cleanup();

		void executeCommandList(ID3D12CommandList* const _commandList)const;

	public:
		ID3D12CommandQueue* getCommandQueue()const { return m_CommandQueue.Get(); }

	private:
		core::ComPtr<ID3D12CommandQueue> m_CommandQueue;
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_QUEUE_IMPL_H
