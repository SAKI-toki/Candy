#ifndef CANDY_GRAPHIC_ROOT_SIGNATURE_IMPL_H
#define CANDY_GRAPHIC_ROOT_SIGNATURE_IMPL_H

#include <Graphic/GraphicInclude.h>

#include "StartupInfo/GraphicRootSignatureStartupInfoImpl.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class RootSignatureImpl
	{
	protected:
		void startup(ID3D12Device* const _device, const D3D12_ROOT_SIGNATURE_DESC _rootSignatureDesc);
		void cleanup();

	public:
		ID3D12RootSignature* getRootSignature()const { return m_RootSignature.Get(); }

	private:
		core::ComPtr<ID3D12RootSignature> m_RootSignature;
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_ROOT_SIGNATURE_IMPL_H
