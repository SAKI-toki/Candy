#include "GraphicPipelineStartupInfo.h"
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/Shader/Vertex/GraphicVertexShader.h>
#include <Graphic/Shader/Pixel/GraphicPixelShader.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

void PipelineStartupInfo::initialize()
{
	PipelineStartupInfoImpl::initialize();
}

void PipelineStartupInfo::setVertexShader(const VertexShader& _shader)
{
	PipelineStartupInfoImpl::setVertexShader(_shader.getShader());
}

void PipelineStartupInfo::setPixelShader(const PixelShader& _shader)
{
	PipelineStartupInfoImpl::setPixelShader(_shader.getShader());
}

void PipelineStartupInfo::setRenderTaretFormat(const s32 _index, const types::GRAPHIC_FORMAT _graphicFormat)
{
	PipelineStartupInfoImpl::setRenderTaretFormat(_index, _graphicFormat);
}

void PipelineStartupInfo::setRenderTaretCount(const s32 _count)
{
	PipelineStartupInfoImpl::setRenderTaretCount(_count);
}

void PipelineStartupInfo::setDepthStencilFormat(const types::GRAPHIC_FORMAT _graphicFormat)
{
	PipelineStartupInfoImpl::setDepthStencilFormat(_graphicFormat);
}

void PipelineStartupInfo::setInputLayoutElement(const s32 _index, const types::SHADER_SEMANTIC_TYPE _shaderSemanticType,
	const s32 _semanticIndex, const types::GRAPHIC_FORMAT _graphicFormat)
{
	PipelineStartupInfoImpl::setInputLayoutElement(_index, _shaderSemanticType, _semanticIndex, _graphicFormat);
}

void PipelineStartupInfo::setInputLayoutCount(const s32 _count)
{
	PipelineStartupInfoImpl::setInputLayoutCount(_count);
}

void PipelineStartupInfo::setEnableDepth(const bool _isEnableDepth)
{
	PipelineStartupInfoImpl::setEnableDepth(_isEnableDepth);
}

void PipelineStartupInfo::setEnableStencil(const bool _isEnableStencil)
{
	PipelineStartupInfoImpl::setEnableStencil(_isEnableStencil);
}

void PipelineStartupInfo::setEnableBlend(const s32 _renderTargetIndex, const bool _isEnableBlend)
{
	PipelineStartupInfoImpl::setEnableBlend(_renderTargetIndex, _isEnableBlend);
}

void PipelineStartupInfo::setFillMode(const types::FILL_MODE _fillMode)
{
	PipelineStartupInfoImpl::setFillMode(_fillMode);
}

void PipelineStartupInfo::setRootSignature(const RootSignature& _rootSignature)
{
	PipelineStartupInfoImpl::setRootSignature(_rootSignature.getRootSignature());
}

CANDY_GRAPHIC_NAMESPACE_END
