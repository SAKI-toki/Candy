#ifndef CANDY_SOUND_TYPE_H
#define CANDY_SOUND_TYPE_H

#include <Sound/SoundInclude.h>

CANDY_SOUND_NAMESPACE_BEGIN

namespace types
{
	enum CALL_SE_FLAG
	{
		CALL_SE_FLAG_NONE = 0,
		CALL_SE_FLAG_LOOP = (1 << 0),
	};
}

CANDY_SOUND_NAMESPACE_END

#endif // CANDY_SOUND_TYPE_H
