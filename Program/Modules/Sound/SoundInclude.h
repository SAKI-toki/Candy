/*****************************************************************//**
 * \file   SoundInclude.h
 * \brief  Graphicのインクルードファイル
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_SOUND_INCLUDE_H
#define CANDY_SOUND_INCLUDE_H

#include "Core/Core.h"

#define CANDY_SOUND_NAMESPACE_NAME sound

#define CANDY_SOUND_NAMESPACE_BEGIN CANDY_NAMESPACE_BEGIN namespace CANDY_SOUND_NAMESPACE_NAME{
#define CANDY_SOUND_NAMESPACE_END } CANDY_NAMESPACE_END

#include <Sound/Type/SoudType.h>

#endif // CANDY_SOUND_INCLUDE_H
