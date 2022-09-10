/*****************************************************************//**
 * \file   __GraphicCpp.cpp
 * \brief  グラフィック関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Buffer/GraphicBuffer.cpp"
#include "Buffer/StartupInfo/GraphicBufferStartupInfo.cpp"

#include "BufferView/Vertex/GraphicVertexBufferView.cpp"
#include "BufferView/Index/GraphicIndexBufferView.cpp"

#include "CommandList/GraphicCommandList.cpp"

#include "CommandQueue/GraphicCommandQueue.cpp"

#include "Config/GraphicConfig.cpp"

#include "Descriptor/GraphicDescriptor.cpp"
#include "Descriptor/Handle/CPU/GraphicDescriptorCpuHandle.cpp"
#include "Descriptor/Handle/GPU/GraphicDescriptorGpuHandle.cpp"

#include "Device/GraphicDevice.cpp"

#include "Fence/GraphicFence.cpp"

#include "Module/GraphicModule.cpp"

#include "Pipeline/GraphicPipeline.cpp"
#include "Pipeline/StartupInfo/GraphicPipelineStartupInfo.cpp"

#include "ResourceLifetime/GraphicResourceLifetime.cpp"

#include "RootSignature/GraphicRootSignature.cpp"
#include "RootSignature/StartupInfo/GraphicRootSignatureStartupInfo.cpp"

#include "ScissorRect/GraphicScissorRect.cpp"

#include "Shader/GraphicShaderManager.cpp"
#include "Shader/Base/GraphicBaseShader.cpp"
#include "Shader/Pixel/GraphicPixelShader.cpp"
#include "Shader/Vertex/GraphicVertexShader.cpp"

#include "System/GraphicSystem.cpp"

#include "SwapChain/GraphicSwapChain.cpp"

#include "Texture/GraphicTextureUploder.cpp"
#include "Texture/DDS/GraphicReadDDS.cpp"

#include "Types/GraphicTypes.cpp"

#include "Viewport/GraphicViewport.cpp"

#if PLATFORM_WIN

#include "Platform/Win/Buffer/GraphicBufferImpl.cpp"
#include "Platform/Win/Buffer/StartupInfo/GraphicBufferStartupInfoImpl.cpp"

#include "Platform/Win/BufferView/Vertex/GraphicVertexBufferViewImpl.cpp"
#include "Platform/Win/BufferView/Index/GraphicIndexBufferViewImpl.cpp"

#include "Platform/Win/CommandList/GraphicCommandListImpl.cpp"

#include "Platform/Win/CommandQueue/GraphicCommandQueueImpl.cpp"

#include "Platform/Win/Descriptor/GraphicDescriptorImpl.cpp"
#include "Platform/Win/Descriptor/Handle/CPU/GraphicDescriptorCpuHandleImpl.cpp"
#include "Platform/Win/Descriptor/Handle/GPU/GraphicDescriptorGpuHandleImpl.cpp"

#include "Platform/Win/Device/GraphicDeviceImpl.cpp"

#include "Platform/Win/Fence/GraphicFenceImpl.cpp"

#include "Platform/Win/Pipeline/GraphicPipelineImpl.cpp"
#include "Platform/Win/Pipeline/StartupInfo/GraphicPipelineStartupInfoImpl.cpp"

#include "Platform/Win/RootSignature/GraphicRootSignatureImpl.cpp"
#include "Platform/Win/RootSignature/StartupInfo/GraphicRootSignatureStartupInfoImpl.cpp"

#include "Platform/Win/ScissorRect/GraphicScissorRectImpl.cpp"

#include "Platform/Win/Shader/Base/GraphicBaseShaderImpl.cpp"

#include "Platform/Win/SwapChain/GraphicSwapChainImpl.cpp"

#include "Platform/Win/System/GraphicSystemImpl.cpp"

#include "Platform/Win/Types/GraphicTypeConvert.cpp"

#include "Platform/Win/Viewport/GraphicViewportImpl.cpp"

#endif // PLATFORM_WIN