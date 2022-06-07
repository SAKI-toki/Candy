#include "Sound.h"
#include <FileSystem/FileSystem.h>

#if PLATFORM_WIN
#include "Platform/Win/SoundImpl.h"
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Sound
{

}

void Sound::Startup()
{
	Impl::Startup();
}

void Sound::Cleanup()
{
	Impl::Cleanup();
}

void Sound::Update()
{
	Impl::Update();
}

void Sound::CallSe(const std::string& _soundName, const u32 _callSeFlag)
{
	Sound::Impl::CallSe(_soundName, _callSeFlag);
}

CANDY_NAMESPACE_END
