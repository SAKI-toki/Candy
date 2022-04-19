#ifndef CANDY_GRAPHIC_COMMAND_LIST_IMPL_H
#define CANDY_GRAPHIC_COMMAND_LIST_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class CommandListImpl
	{
	public:
		void startup(ID3D12Device* const _device, const COMMAND_LIST_TYPE _commandListType);
		void cleanup();

	private:
		ComPtr<ID3D12CommandAllocator> m_CommandAllocator;
		ComPtr<ID3D12CommandList> m_CommandList;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_LIST_IMPL_H
