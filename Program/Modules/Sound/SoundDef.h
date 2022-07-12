#ifndef CANDY_SOUND_DEF_H
#define CANDY_SOUND_DEF_H

#include <Sound/SoundInclude.h>

CANDY_NAMESPACE_BEGIN

namespace Sound
{
	enum CALL_SE_FLAG
	{
		CALL_SE_FLAG_NONE = 0,
		CALL_SE_FLAG_LOOP = (1 << 0),
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_SOUND_DEF_H
