/*****************************************************************//**
 * \file   __TimeCpp.cpp
 * \brief  時間関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Time.cpp"
#include "Tick.cpp"

#if PLATFORM_WIN
#include "Platform/Win/TimeImpl.cpp"
#include "Platform/Win/TickImpl.cpp"
#endif