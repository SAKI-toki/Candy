#ifndef CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_IMPL_H
#define CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	class PipelineStartupInfoImpl
	{
	protected:
		PipelineStartupInfoImpl();

		void initialize();

		void setVertexShader(const D3D12_SHADER_BYTECODE& _shader);
		void setPixelShader(const D3D12_SHADER_BYTECODE& _shader);
		
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

		void setRootSignature(ID3D12RootSignature* const _rootSignature);

	public:
		D3D12_GRAPHICS_PIPELINE_STATE_DESC getStartupInfo()const { return m_StartupInfo; }

	private:
		D3D12_GRAPHICS_PIPELINE_STATE_DESC m_StartupInfo{};
		D3D12_INPUT_ELEMENT_DESC m_InputElementDescs[32]{};
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_PIPELINE_STARTUP_INFO_IMPL_H
