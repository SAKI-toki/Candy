/*****************************************************************//**
 * \file   __CoreProxyCpp.cpp
 * \brief  CoreProxy関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#include "Config/CoreProxyConfig.cpp"

#include "Debug/Assert/CoreProxyAssert.cpp"
#include "Debug/Log/CoreProxyLog.cpp"

#include "EntryPoint/CoreProxyEntryPoint.cpp"

#include "Module/CoreProxyModuleManager.cpp"

#if PLATFORM_WIN

#include "Platform/Win/Debug/Assert/CoreProxyAssertImpl.cpp"
#include "Platform/Win/Debug/Log/CoreProxyLogImpl.cpp"

#endif // PLATFORM_WIN
