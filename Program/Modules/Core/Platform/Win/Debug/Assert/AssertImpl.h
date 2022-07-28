/*****************************************************************//**
 * \file   Assert.h
 * \brief  アサートの呼び出しの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_DEBUG_ASSERT_IMPL_H
#define CANDY_CORE_DEBUG_ASSERT_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

#define CANDY_ASSERT_HRESULT(EXPR) CANDY_ASSERT(SUCCEEDED(EXPR))

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_DEBUG_ASSERT_IMPL_H
