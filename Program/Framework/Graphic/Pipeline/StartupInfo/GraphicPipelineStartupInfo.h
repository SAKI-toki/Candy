#ifndef CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H
#define CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H

#include <Graphic/GraphicDef.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Pipeline/StartupInfo/GraphicPipelineStartupInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Shader
{
	class VertexShader;
	class PixelShader;
}

namespace Graphic
{
	class RootSignature;

	class PipelineStartupInfo : public Impl::PipelineStartupInfoImpl
	{
	public:
		void initialize();

		void setVertexShader(const Shader::VertexShader& _shader);
		void setPixelShader(const Shader::PixelShader& _shader);
		
		void setRenderTaretFormat(const s32 _index, const GRAPHIC_FORMAT _graphicFormat);
		void setRenderTaretCount(const s32 _count);
		void setDepthStencilFormat(const GRAPHIC_FORMAT _graphicFormat);
		
		void setInputLayoutElement(const s32 _index, const SHADER_SEMANTIC_TYPE _shaderSemanticType,
			const s32 _semanticIndex, const GRAPHIC_FORMAT _graphicFormat);
		void setInputLayoutCount(const s32 _count);
		
		void setEnableDepth(const bool _isEnableDepth);
		void setEnableStencil(const bool _isEnableStencil);

		void setEnableBlend(const s32 _renderTargetIndex, const bool _isEnableBlend);

		void setFillMode(const FILL_MODE _fillMode);

		void setRootSignature(const RootSignature& _rootSignature);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H
