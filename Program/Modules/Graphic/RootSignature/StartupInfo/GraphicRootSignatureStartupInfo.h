#ifndef CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_H
#define CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_H

#include <Graphic/GraphicInclude.h>

#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/RootSignature/StartupInfo/GraphicRootSignatureStartupInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_GRAPHIC_NAMESPACE_BEGIN

class RootSignatureStartupInfo : public impl::RootSignatureStartupInfoImpl
{
public:
	void initialize();

	void setDescriptorRange(const s32 _rootParameterIndex, const types::ShaderRegisterInfo _shaderRegisterInfo,
		const s32 _numDescriptor, const types::DESCRIPTOR_RANGE_TYPE _descriptorRangeType);
	void setRootParameterCount(const s32 _count);
	void setStaticSampler(const s32 _index, const types::ShaderRegisterInfo _shaderRegisterInfo,
		const types::FILTER_TYPE _filterType, const types::TEXTURE_ADDRESS_MODE _textureAddressMode);
	void setStaticSamplerCount(const s32 _count);

	void onRootSignatureFlag(const types::ROOT_SIGNATURE_FLAG _rootSignatureFlag);
	void offRootSignatureFlag(const types::ROOT_SIGNATURE_FLAG _rootSignatureFlag);
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_H
