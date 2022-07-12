#ifndef CANDY_SOUND_IMPL_H
#define CANDY_SOUND_IMPL_H

#include <Sound/SoundInclude.h>

#include <Sound/SoundDef.h>

CANDY_NAMESPACE_BEGIN

namespace Sound::Impl
{
	void Startup();
	void Cleanup();

	void Update();

	void CallSe(const std::string& _soundName, const u32 _callSeFlag);
}

CANDY_NAMESPACE_END

#endif // CANDY_SOUND_IMPL_H
