#include "Graphic.cpp"
#include "GraphicDef.cpp"

#include "Device/GraphicDevice.cpp"
#include "CommandQueue/GraphicCommandQueue.cpp"
#include "CommandList/GraphicCommandList.cpp"
#include "Buffer/GraphicBuffer.cpp"

#if PLATFORM_WIN
#include "Platform/Win/GraphicDefWin.cpp"
#include "Platform/Win/Device/GraphicDeviceImpl.cpp"
#include "Platform/Win/CommandQueue/GraphicCommandQueueImpl.cpp"
#include "Platform/Win/CommandList/GraphicCommandListImpl.cpp"
#include "Platform/Win/Buffer/GraphicBufferImpl.cpp"
#endif // PLATFORM_WIN