#ifndef CANDY_SOUND_SYSTEM_H
#define CANDY_SOUND_SYSTEM_H

#include <Sound/SoundInclude.h>

CANDY_SOUND_NAMESPACE_BEGIN

namespace System
{
	void Startup();
	void Cleanup();

	void Update();

	void CallSe(const std::string_view _soundName, const u32 _callSeFlag = 0);
}

CANDY_SOUND_NAMESPACE_END

#endif // CANDY_SOUND_SYSTEM_H
