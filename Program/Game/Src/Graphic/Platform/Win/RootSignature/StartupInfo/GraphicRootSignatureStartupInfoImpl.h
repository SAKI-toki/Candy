#ifndef CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_IMPL_H
#define CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>
#include <Graphic/Platform/Win/Descriptor/GraphicDescriptorImpl.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class RootSignatureStartupInfoImpl
	{
	protected:
		RootSignatureStartupInfoImpl();

		void setDescriptorRange(const s32 _rootParameterIndex, const ShaderRegisterType& _shaderRegisterType, const DescriptorImpl& _descriptor);
		void setRootParameterCount(const s32 _count);
		void setStaticSampler(const s32 _index, const ShaderRegisterType _shaderRegisterType, const FILTER_TYPE _filterType);
		void setStaticSamplerCount(const s32 _count);

	public:
		D3D12_ROOT_SIGNATURE_DESC getStartupInfo()const { return m_StartupInfo; }

	private:
		D3D12_ROOT_SIGNATURE_DESC m_StartupInfo{};
		D3D12_DESCRIPTOR_RANGE m_DescriptorRanges[32]{};
		D3D12_ROOT_PARAMETER m_RootParameters[32]{};
		D3D12_STATIC_SAMPLER_DESC m_StaticSamplerDescs[32]{};
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_IMPL_H
