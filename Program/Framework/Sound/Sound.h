#ifndef CANDY_SOUND_H
#define CANDY_SOUND_H

CANDY_NAMESPACE_BEGIN

namespace Sound
{
	void Startup();
	void Cleanup();

	void Update();

	void CallSe(const std::string& _soundName);
}

CANDY_NAMESPACE_END

#endif // CANDY_SOUND_H
