/*****************************************************************//**
 * \file   Graphic.h
 * \brief  Graphicファイルのインクルード
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_GRAPHIC_H
#define CANDY_GRAPHIC_H

#include "GraphicInclude.h"

#include "Buffer/GraphicBuffer.h"
#include "Buffer/StartupInfo/GraphicBufferStartupInfo.h"

#include "BufferView/Index/GraphicIndexBufferView.h"
#include "BufferView/Vertex/GraphicVertexBufferView.h"

#include "CommandList/GraphicCommandList.h"

#include "CommandQueue/GraphicCommandQueue.h"

#include "Config/GraphicConfig.h"

#include "Descriptor/GraphicDescriptor.h"
#include "Descriptor/Handle/CPU/GraphicDescriptorCpuHandle.h"
#include "Descriptor/Handle/GPU/GraphicDescriptorGpuHandle.h"

#include "Device/GraphicDevice.h"

#include "Fence/GraphicFence.h"

#include "Module/GraphicModule.h"

#include "Pipeline/GraphicPipeline.h"
#include "Pipeline/StartupInfo/GraphicPipelineStartupInfo.h"

#include "ResourceLifetime/GraphicResourceLifetime.h"

#include "RootSignature/GraphicRootSignature.h"
#include "RootSignature/StartupInfo/GraphicRootSignatureStartupInfo.h"

#include "ScissorRect/GraphicScissorRect.h"

#include "Shader/GraphicShaderManager.h"
#include "Shader/Base/GraphicBaseShader.h"
#include "Shader/Pixel/GraphicPixelShader.h"
#include "Shader/Vertex/GraphicVertexShader.h"

#include "SwapChain/GraphicSwapChain.h"

#include "System/GraphicSystem.h"

#include "Texture/GraphicTextureUploder.h"
#include "Texture/DDS/GraphicReadDDS.h"

#include "Types/GraphicTypes.h"

#include "Viewport/GraphicViewport.h"

#endif // CANDY_GRAPHIC_H
