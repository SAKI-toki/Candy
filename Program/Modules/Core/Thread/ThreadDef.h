/*****************************************************************//**
 * \file   ThreadDef.h
 * \brief  スレッドの定義
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CANDY_CORE_THREAD_DEF_H
#define CANDY_CORE_THREAD_DEF_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

enum class THREAD_PRIORITY
{
	CRITICAL,
	HIGHEST,
	ABOVE_NORMAL,
	NORMAL,
	BELOW_NORMAL,
	LOWEST,
};

struct CreateThreadOption
{
	bool m_bSuspend = false;
	s32 m_CoreNo = -1;
	THREAD_PRIORITY m_Priority = THREAD_PRIORITY::NORMAL;
};

struct ThreadFunctionArg
{
	std::function<void(void*)> m_Func;
	void* m_Args = nullptr;
	CreateThreadOption m_Option{};
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_THREAD_DEF_H
