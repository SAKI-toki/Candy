/*****************************************************************//**
 * \file   __GraphicCpp.cpp
 * \brief  グラフィック関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Graphic.cpp"
#include "GraphicDef.cpp"

#include "Device/GraphicDevice.cpp"
#include "CommandQueue/GraphicCommandQueue.cpp"
#include "CommandList/GraphicCommandList.cpp"
#include "SwapChain/GraphicSwapChain.cpp"
#include "Buffer/GraphicBuffer.cpp"
#include "Buffer/StartupInfo/GraphicBufferStartupInfo.cpp"
#include "BufferView/Vertex/GraphicVertexBufferView.cpp"
#include "BufferView/Index/GraphicIndexBufferView.cpp"
#include "Fence/GraphicFence.cpp"
#include "Viewport/GraphicViewport.cpp"
#include "ScissorRect/GraphicScissorRect.cpp"
#include "Descriptor/GraphicDescriptor.cpp"
#include "Descriptor/Handle/CPU/GraphicDescriptorCpuHandle.cpp"
#include "Descriptor/Handle/GPU/GraphicDescriptorGpuHandle.cpp"
#include "Pipeline/GraphicPipeline.cpp"
#include "Pipeline/StartupInfo/GraphicPipelineStartupInfo.cpp"
#include "RootSignature/GraphicRootSignature.cpp"
#include "RootSignature/StartupInfo/GraphicRootSignatureStartupInfo.cpp"
#include "ResourceManager/GraphicResourceManager.cpp"

#if PLATFORM_WIN
#include "Platform/Win/GraphicImpl.cpp"
#include "Platform/Win/GraphicDefWin.cpp"
#include "Platform/Win/Device/GraphicDeviceImpl.cpp"
#include "Platform/Win/CommandQueue/GraphicCommandQueueImpl.cpp"
#include "Platform/Win/CommandList/GraphicCommandListImpl.cpp"
#include "Platform/Win/SwapChain/GraphicSwapChainImpl.cpp"
#include "Platform/Win/Buffer/GraphicBufferImpl.cpp"
#include "Platform/Win/Buffer/StartupInfo/GraphicBufferStartupInfoImpl.cpp"
#include "Platform/Win/BufferView/Vertex/GraphicVertexBufferViewImpl.cpp"
#include "Platform/Win/BufferView/Index/GraphicIndexBufferViewImpl.cpp"
#include "Platform/Win/Fence/GraphicFenceImpl.cpp"
#include "Platform/Win/Viewport/GraphicViewportImpl.cpp"
#include "Platform/Win/ScissorRect/GraphicScissorRectImpl.cpp"
#include "Platform/Win/Descriptor/GraphicDescriptorImpl.cpp"
#include "Platform/Win/Descriptor/Handle/CPU/GraphicDescriptorCpuHandleImpl.cpp"
#include "Platform/Win/Descriptor/Handle/GPU/GraphicDescriptorGpuHandleImpl.cpp"
#include "Platform/Win/Pipeline/GraphicPipelineImpl.cpp"
#include "Platform/Win/Pipeline/StartupInfo/GraphicPipelineStartupInfoImpl.cpp"
#include "Platform/Win/RootSignature/GraphicRootSignatureImpl.cpp"
#include "Platform/Win/RootSignature/StartupInfo/GraphicRootSignatureStartupInfoImpl.cpp"
#endif // PLATFORM_WIN