/*****************************************************************//**
 * \file   __MutexCpp.cpp
 * \brief  ミューテックス関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "CriticalSection.cpp"

#if PLATFORM_WIN
#include "Platform/Win/CriticalSectionImpl.cpp"
#endif
