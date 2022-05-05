#include "GraphicPipelineStartupInfo.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	void PipelineStartupInfo::setVertexShader(const Shader::VertexShader& _shader)
	{
		PipelineStartupInfoImpl::setVertexShader(_shader.getShader());
	}

	void PipelineStartupInfo::setPixelShader(const Shader::PixelShader& _shader)
	{
		PipelineStartupInfoImpl::setPixelShader(_shader.getShader());
	}

	void PipelineStartupInfo::setRenderTaretFormat(const s32 _index, const GRAPHIC_FORMAT _graphicFormat)
	{
		PipelineStartupInfoImpl::setRenderTaretFormat(_index, _graphicFormat);
	}

	void PipelineStartupInfo::setRenderTaretCount(const s32 _count)
	{
		PipelineStartupInfoImpl::setRenderTaretCount(_count);
	}

	void PipelineStartupInfo::setDepthStencilFormat(const GRAPHIC_FORMAT _graphicFormat)
	{
		PipelineStartupInfoImpl::setDepthStencilFormat(_graphicFormat);
	}

	void PipelineStartupInfo::setInputLayoutElement(const s32 _index, const SHADER_SEMANTIC_TYPE _shaderSemanticType,
		const s32 _semanticIndex, const GRAPHIC_FORMAT _graphicFormat)
	{
		PipelineStartupInfoImpl::setInputLayoutElement(_index, _shaderSemanticType, _semanticIndex, _graphicFormat);
	}

	void PipelineStartupInfo::setInputLayoutCount(const s32 _count)
	{
		PipelineStartupInfoImpl::setInputLayoutCount(_count);
	}

	void PipelineStartupInfo::setRootSignature(const RootSignature& _rootSignature)
	{
		PipelineStartupInfoImpl::setRootSignature(_rootSignature.getRootSignature());
	}
}

CANDY_NAMESPACE_END
