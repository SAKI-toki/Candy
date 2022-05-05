#ifndef CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H
#define CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Shader/Vertex/VertexShader.h>
#include <Shader/Pixel/PixelShader.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Pipeline/StartupInfo/GraphicPipelineStartupInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class PipelineStartupInfo : public PipelineStartupInfoImpl
	{
	public:
		void setVertexShader(const Shader::VertexShader& _shader);
		void setPixelShader(const Shader::PixelShader& _shader);
		void setRenderTaretFormat(const s32 _index, const GRAPHIC_FORMAT _graphicFormat);
		void setRenderTaretCount(const s32 _count);
		void setDepthStencilFormat(const GRAPHIC_FORMAT _graphicFormat);
		void setInputLayoutElement(const s32 _index, const SHADER_SEMANTIC_TYPE _shaderSemanticType,
			const s32 _semanticIndex, const GRAPHIC_FORMAT _graphicFormat);
		void setInputLayoutCount(const s32 _count);
		void setRootSignature(const RootSignature& _rootSignature);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H
