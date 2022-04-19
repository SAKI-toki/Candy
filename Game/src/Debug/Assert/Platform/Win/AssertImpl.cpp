#include "AssertImpl.h"

CANDY_NAMESPACE_BEGIN

void assertImpl(const char* const _expr, const char* const _fileName, const u32 _lineNo, const char* const _funcName)
{
	std::string assertMessage;
	assertMessage = assertMessage + "�ꏊ:" + _fileName + "(" + std::to_string(_lineNo) + "):" + _funcName + "\n";
	assertMessage = assertMessage + "�s��:" + _expr;

	::MessageBox(NULL, assertMessage.c_str(), "�G���[", MB_OK);

	std::abort();
}

CANDY_NAMESPACE_END
