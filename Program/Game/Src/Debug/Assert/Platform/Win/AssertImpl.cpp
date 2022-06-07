/*****************************************************************//**
 * \file   AssertImpl.cpp
 * \brief  アサートの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "AssertImpl.h"

CANDY_NAMESPACE_BEGIN

// アサートの実装部
void assertImpl(const char* const _expr, const char* const _fileName, const u32 _lineNo, const char* const _funcName)
{
	std::string assertMessage;
	assertMessage = assertMessage + "場所:" + _fileName + "(" + std::to_string(_lineNo) + "):" + _funcName + "\n";
	assertMessage = assertMessage + "不正:" + _expr;

	::MessageBox(NULL, assertMessage.c_str(), "エラー", MB_OK);

	std::abort();
}

CANDY_NAMESPACE_END
