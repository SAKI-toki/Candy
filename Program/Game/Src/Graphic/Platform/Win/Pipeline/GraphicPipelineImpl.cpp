#include "GraphicPipelineImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	void PipelineImpl::startup(ID3D12Device* const _device, const D3D12_GRAPHICS_PIPELINE_STATE_DESC _pipelineStateDesc)
	{
		CANDY_ASSERT_HRESULT(_device->CreateGraphicsPipelineState(&_pipelineStateDesc, IID_PPV_ARGS(m_Pipeline.GetAddressOf())));
	}

	void PipelineImpl::cleanup()
	{
		m_Pipeline.Reset();
	}
}

CANDY_NAMESPACE_END
