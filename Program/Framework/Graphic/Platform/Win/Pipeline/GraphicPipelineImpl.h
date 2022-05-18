#ifndef CANDY_GRAPHIC_PIPELINE_IMPL_H
#define CANDY_GRAPHIC_PIPELINE_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>
#include "StartupInfo/GraphicPipelineStartupInfoImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	class PipelineImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const D3D12_GRAPHICS_PIPELINE_STATE_DESC _pipelineStateDesc);
		void cleanup();

	public:
		ID3D12PipelineState* getPipeline()const { return m_Pipeline.Get(); }

	private:
		ComPtr<ID3D12PipelineState> m_Pipeline;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_PIPELINE_IMPL_H
