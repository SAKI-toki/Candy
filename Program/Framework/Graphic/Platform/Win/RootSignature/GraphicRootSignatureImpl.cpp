#include "GraphicRootSignatureImpl.h"

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	void RootSignatureImpl::startup(ID3D12Device* const _device, const D3D12_ROOT_SIGNATURE_DESC _rootSignatureDesc)
	{
		ComPtr<ID3DBlob> blob;
		CANDY_ASSERT_HRESULT(D3D12SerializeRootSignature(&_rootSignatureDesc, D3D_ROOT_SIGNATURE_VERSION_1, &blob, nullptr));

		CANDY_ASSERT_HRESULT(_device->CreateRootSignature(0, blob->GetBufferPointer(),
			blob->GetBufferSize(), IID_PPV_ARGS(m_RootSignature.GetAddressOf())));
	}

	void RootSignatureImpl::cleanup()
	{
		m_RootSignature.Reset();
	}
}

CANDY_NAMESPACE_END
