/*****************************************************************//**
 * \file   TimeImpl.h
 * \brief  時間の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_TIME_IMPL_H
#define CANDY_CORE_TIME_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Time::Impl
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();

	// 秒
	f32 ToSec(const LARGE_INTEGER _value);
	// ミリ秒
	f32 ToMilliSec(const LARGE_INTEGER _value);
	// マイクロ秒
	f32 ToMicroSec(const LARGE_INTEGER _value);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_TIME_IMPL_H
