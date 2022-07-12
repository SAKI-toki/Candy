#ifndef CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H
#define CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H

#include <Graphic/GraphicInclude.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/Pipeline/StartupInfo/GraphicPipelineStartupInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class VertexShader;
class PixelShader;
class RootSignature;

class PipelineStartupInfo : public impl::PipelineStartupInfoImpl
{
public:
	void initialize();

	void setVertexShader(const VertexShader& _shader);
	void setPixelShader(const PixelShader& _shader);

	void setRenderTaretFormat(const s32 _index, const types::GRAPHIC_FORMAT _graphicFormat);
	void setRenderTaretCount(const s32 _count);
	void setDepthStencilFormat(const types::GRAPHIC_FORMAT _graphicFormat);

	void setInputLayoutElement(const s32 _index, const types::SHADER_SEMANTIC_TYPE _shaderSemanticType,
		const s32 _semanticIndex, const types::GRAPHIC_FORMAT _graphicFormat);
	void setInputLayoutCount(const s32 _count);

	void setEnableDepth(const bool _isEnableDepth);
	void setEnableStencil(const bool _isEnableStencil);

	void setEnableBlend(const s32 _renderTargetIndex, const bool _isEnableBlend);

	void setFillMode(const types::FILL_MODE _fillMode);

	void setRootSignature(const RootSignature& _rootSignature);
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_H
