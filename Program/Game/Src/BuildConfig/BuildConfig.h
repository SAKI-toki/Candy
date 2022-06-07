/*****************************************************************//**
 * \file   BuildConfig.h
 * \brief  ビルド時の設定
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_BUILD_CONFIG_H
#define CANDY_BUILD_CONFIG_H

// Debugビルド時はBUILD_DEBUG, Releaseビルド時はBUILD_RELEASE
#if _DEBUG
#define BUILD_DEBUG (1)
#define BUILD_RELEASE (0)
#else
#define BUILD_DEBUG (0)
#define BUILD_RELEASE (1)
#endif // _DEBUG

#endif // CANDY_BUILD_CONFIG_H
