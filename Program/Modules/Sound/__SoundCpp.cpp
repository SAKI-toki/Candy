/*****************************************************************//**
 * \file   __SoundCpp.cpp
 * \brief  サウンド関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Sound.cpp"
#include "SoundDef.cpp"

#if PLATFORM_WIN
#include "Platform/Win/SoundImpl.cpp"
#endif // PLATFORM_WIN
