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

void Sound::CallSe(const std::string& _soundName)
{
	std::string path = Setting::GetDataPath() + std::string{ R"(\Sound\)" } + _soundName;
	const u64 bufSize = FileSystem::GetFileSize(path);
	std::byte* buf = new std::byte[bufSize];
	FileSystem::RequestReadNoWait(path, buf, bufSize);
	Sound::Impl::CallSe(buf, bufSize);
}

CANDY_NAMESPACE_END
