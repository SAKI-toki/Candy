#ifndef CANDY_GRAPHIC_COMMAND_QUEUE_H
#define CANDY_GRAPHIC_COMMAND_QUEUE_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/CommandQueue/GraphicCommandQueueImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Device;
class CommandList;

class CommandQueue : public impl::CommandQueueImpl
{
public:
	void startup(const Device& _device, const types::COMMAND_LIST_TYPE _commandListType);
	void cleanup();

	void executeCommandList(CommandList& _commandList)const;
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_COMMAND_QUEUE_H
