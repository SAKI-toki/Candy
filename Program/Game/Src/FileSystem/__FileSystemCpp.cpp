/*****************************************************************//**
 * \file   __FileSystemCpp.cpp
 * \brief  ファイルシステム関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "FileSystem.cpp"
#include "FileInfo/FileSystemFileInfo.cpp"
#include "FileEnumerator/FileSystemFileEnumerator.cpp"
#include "Work/FileSystemWork.cpp"
#include "Work/FileSystemWorkHandle.cpp"

#if PLATFORM_WIN
#include "Platform/Win/FileSystemImpl.cpp"
#include "Platform/Win/FileEnumerator/FileSystemFileEnumeratorImpl.cpp"
#include "Platform/Win/FileInfo/FileSystemFileInfoImpl.cpp"
#endif // PLATFORM_WIN
