#ifndef CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_IMPL_H
#define CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_IMPL_H

#include <Graphic/GraphicInclude.h>

#include <Graphic/Platform/Win/Descriptor/GraphicDescriptorImpl.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	class RootSignatureStartupInfoImpl
	{
	protected:
		RootSignatureStartupInfoImpl();

		void initialize();

		void setDescriptorRange(const s32 _rootParameterIndex, const types::ShaderRegisterInfo _shaderRegisterInfo,
			const s32 _numDescriptor, const types::DESCRIPTOR_RANGE_TYPE _descriptorRangeType);
		void setRootParameterCount(const s32 _count);
		void setStaticSampler(const s32 _index, const types::ShaderRegisterInfo _shaderRegisterInfo,
			const types::FILTER_TYPE _filterType, const types::TEXTURE_ADDRESS_MODE _textureAddressMode);
		void setStaticSamplerCount(const s32 _count);

		void onRootSignatureFlag(const types::ROOT_SIGNATURE_FLAG _rootSignatureFlag);
		void offRootSignatureFlag(const types::ROOT_SIGNATURE_FLAG _rootSignatureFlag);

	public:
		D3D12_ROOT_SIGNATURE_DESC getStartupInfo()const { return m_StartupInfo; }

	private:
		D3D12_ROOT_SIGNATURE_DESC m_StartupInfo{};
		D3D12_DESCRIPTOR_RANGE m_DescriptorRanges[32]{};
		D3D12_ROOT_PARAMETER m_RootParameters[32]{};
		D3D12_STATIC_SAMPLER_DESC m_StaticSamplerDescs[32]{};
	};
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_IMPL_H
