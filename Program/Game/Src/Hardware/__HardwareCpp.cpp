/*****************************************************************//**
 * \file   __HardwareCpp.cpp
 * \brief  ハードウェア関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Hardware.cpp"

#if PLATFORM_WIN
#include "Platform/Win/HardwareImpl.cpp"
#endif
