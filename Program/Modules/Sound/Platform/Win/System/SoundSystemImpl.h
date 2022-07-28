#ifndef CANDY_SOUND_SYSTEM_IMPL_H
#define CANDY_SOUND_SYSTEM_IMPL_H

#include <Sound/SoundInclude.h>

CANDY_SOUND_NAMESPACE_BEGIN

namespace System::Impl
{
	void Startup();
	void Cleanup();

	void Update();

	void CallSe(const std::string& _soundName, const u32 _callSeFlag);
}

CANDY_SOUND_NAMESPACE_END

#endif // CANDY_SOUND_SYSTEM_IMPL_H
