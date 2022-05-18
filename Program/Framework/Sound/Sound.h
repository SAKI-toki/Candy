#ifndef CANDY_SOUND_H
#define CANDY_SOUND_H

#include <Sound/SoundDef.h>

CANDY_NAMESPACE_BEGIN

namespace Sound
{
	void Startup();
	void Cleanup();

	void Update();

	void CallSe(const std::string& _soundName, const u32 _callSeFlag = 0);
}

CANDY_NAMESPACE_END

#endif // CANDY_SOUND_H
