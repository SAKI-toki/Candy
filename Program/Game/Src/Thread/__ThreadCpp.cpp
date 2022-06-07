/*****************************************************************//**
 * \file   __ThreadCpp.cpp
 * \brief  �X���b�h�֘A��cpp�t�@�C������
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Thread.cpp"
#include "ThreadSystem.cpp"
#include "ThreadHandle.cpp"

#if PLATFORM_WIN
#include "Platform/Win/ThreadHandleImpl.cpp"
#include "Platform/Win/ThreadSystemImpl.cpp"
#endif
