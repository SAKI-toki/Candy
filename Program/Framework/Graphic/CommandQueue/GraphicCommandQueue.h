#ifndef CANDY_GRAPHIC_COMMAND_QUEUE_H
#define CANDY_GRAPHIC_COMMAND_QUEUE_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/CommandQueue/GraphicCommandQueueImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Device;
	class CommandList;

	class CommandQueue : public Impl::CommandQueueImpl
	{
	public:
		void startup(const Device& _device, const COMMAND_LIST_TYPE _commandListType);
		void cleanup();

		void executeCommandList(CommandList& _commandList)const;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_QUEUE_H
