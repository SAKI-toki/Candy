#include "Graphic.cpp"
#include "GraphicDef.cpp"

#include "Device/GraphicDevice.cpp"
#include "CommandQueue/GraphicCommandQueue.cpp"
#include "CommandList/GraphicCommandList.cpp"
#include "SwapChain/GraphicSwapChain.cpp"
#include "Buffer/RenderTarget/GraphicRenderTarget.cpp"
#include "Buffer/BackBuffer/GraphicBackBuffer.cpp"
#include "Fence/GraphicFence.cpp"

#if PLATFORM_WIN
#include "Platform/Win/GraphicDefWin.cpp"
#include "Platform/Win/Device/GraphicDeviceImpl.cpp"
#include "Platform/Win/CommandQueue/GraphicCommandQueueImpl.cpp"
#include "Platform/Win/CommandList/GraphicCommandListImpl.cpp"
#include "Platform/Win/SwapChain/GraphicSwapChainImpl.cpp"
#include "Platform/Win/Buffer/GraphicBufferImpl.cpp"
#include "Platform/Win/Buffer/RenderTarget/GraphicRenderTargetImpl.cpp"
#include "Platform/Win/Buffer/BackBuffer/GraphicBackBufferImpl.cpp"
#include "Platform/Win/Fence/GraphicFenceImpl.cpp"
#endif // PLATFORM_WIN