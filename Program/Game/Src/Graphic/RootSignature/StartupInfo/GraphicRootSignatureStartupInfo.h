#ifndef CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_H
#define CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>

#if PLATFORM_WIN
#include <Graphic/Platform/Win/RootSignature/StartupInfo/GraphicRootSignatureStartupInfoImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class RootSignatureStartupInfo : public RootSignatureStartupInfoImpl
	{
	public:
		void setDescriptorRange(const s32 _rootParameterIndex, const ShaderRegisterType& _shaderRegisterType, const Descriptor& _descriptor);
		void setRootParameterCount(const s32 _count);
		void setStaticSampler(const s32 _index, const ShaderRegisterType _shaderRegisterType, const FILTER_TYPE _filterType);
		void setStaticSamplerCount(const s32 _count);
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_ROOT_SIGNATURE_STARTUP_INFO_H
