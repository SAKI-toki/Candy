#include "SoundSystem.h"
#include <Core/FileSystem/FileSystem.h>

#if PLATFORM_WIN
#include <Sound/Platform/Win/System/SoundSystemImpl.h>
#endif // PLATFORM_WIN

CANDY_SOUND_NAMESPACE_BEGIN

namespace System
{

}

void System::Startup()
{
	Impl::Startup();
}

void System::Cleanup()
{
	Impl::Cleanup();
}

void System::Update()
{
	Impl::Update();
}

void System::CallSe(const std::string_view _soundName, const u32 _callSeFlag)
{
	Impl::CallSe(_soundName, _callSeFlag);
}

CANDY_SOUND_NAMESPACE_END
