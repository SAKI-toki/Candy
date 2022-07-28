/*****************************************************************//**
 * \file   __SoundCpp.cpp
 * \brief  サウンド関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Module/SoundModule.cpp"

#include "System/SoundSystem.cpp"

#if PLATFORM_WIN
#include "Platform/Win/System/SoundSystemImpl.cpp"
#endif // PLATFORM_WIN
