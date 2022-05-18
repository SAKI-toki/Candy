#ifndef CANDY_SOUND_IMPL_H
#define CANDY_SOUND_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Sound::Impl
{
	void Startup();
	void Cleanup();

	void Update();

	void CallSe(const std::byte* const _buf, const u64 _bufSize);
}

CANDY_NAMESPACE_END

#endif // CANDY_SOUND_IMPL_H
