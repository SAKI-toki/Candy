/*****************************************************************//**
 * \file   BuildConfig.h
 * \brief  ビルド時の設定
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_BUILD_CONFIG_H
#define CANDY_BUILD_CONFIG_H

#include <Core/CoreInclude.h>

// Debugビルド時はBUILD_DEBUG, Releaseビルド時はBUILD_RELEASE
#if _DEBUG
#define BUILD_DEBUG (1)
#define BUILD_RELEASE (0)
#else // _DEBUG
#define BUILD_DEBUG (0)
#define BUILD_RELEASE (1)
#endif // _DEBUG

#ifdef _MSC_VER
#pragma warning(disable : 4201) // 無名構造体
#pragma warning(disable : 4324) // 構造体のパッド
#endif // _MSC_VER

#endif // CANDY_BUILD_CONFIG_H
