/*****************************************************************//**
 * \file   __EntryPointCpp.cpp
 * \brief  エントリーポイント関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Main.cpp"
#if PLATFORM_WIN
#include "Platform/Win/MainImpl.cpp"
#endif // PLATFORM_WIN
