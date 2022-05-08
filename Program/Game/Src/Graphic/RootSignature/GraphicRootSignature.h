#ifndef CANDY_GRAPHIC_ROOT_SIGNATURE_H
#define CANDY_GRAPHIC_ROOT_SIGNATURE_H

#include <Graphic/GraphicDef.h>
#include <Graphic/Device/GraphicDevice.h>
#include "StartupInfo/GraphicRootSignatureStartupInfo.h"

#if PLATFORM_WIN
#include <Graphic/Platform/Win/RootSignature/GraphicRootSignatureImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class RootSignature : public Impl::RootSignatureImpl
	{
	public:
		void startup(const Device& _device, const RootSignatureStartupInfo& _startupInfo);
		void cleanup();
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_ROOT_SIGNATURE_H
