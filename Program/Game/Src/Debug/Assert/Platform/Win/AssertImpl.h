/*****************************************************************//**
 * \file   AssertImpl.h
 * \brief  アサートの実装部
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_DEBUG_ASSERT_IMPL_H
#define CANDY_DEBUG_ASSERT_IMPL_H

CANDY_NAMESPACE_BEGIN

// アサートの実装部
void assertImpl(const char* const _expr, const char* const _fileName, const u32 _lineNo, const char* const _funcName);

CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_ASSERT_IMPL_H
