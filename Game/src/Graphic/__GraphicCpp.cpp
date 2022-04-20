#include "Graphic.cpp"
#include "GraphicDef.cpp"

#include "Device/GraphicDevice.cpp"
#include "CommandQueue/GraphicCommandQueue.cpp"
#include "CommandList/GraphicCommandList.cpp"
#include "SwapChain/GraphicSwapChain.cpp"
#include "RenderTarget/GraphicRenderTarget.cpp"

#if PLATFORM_WIN
#include "Platform/Win/GraphicDefWin.cpp"
#include "Platform/Win/Device/GraphicDeviceImpl.cpp"
#include "Platform/Win/CommandQueue/GraphicCommandQueueImpl.cpp"
#include "Platform/Win/CommandList/GraphicCommandListImpl.cpp"
#include "Platform/Win/SwapChain/GraphicSwapChainImpl.cpp"
#include "Platform/Win/RenderTarget/GraphicRenderTargetImpl.cpp"
#endif // PLATFORM_WIN