/*****************************************************************//**
 * \file   __UtilityCpp.cpp
 * \brief  ユーティリティ関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Path/Path.cpp"
#include "StringSystem/Convert/StringSystemConvert.cpp"

#if PLATFORM_WIN
#include "Platform/Win/StringSystem/Convert/StringSystemConvertImpl.cpp"
#endif // PLATFORM_WIN
