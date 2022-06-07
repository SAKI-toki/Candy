/*****************************************************************//**
 * \file   LogImpl.cpp
 * \brief  �f�o�b�O���O�̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "LogImpl.h"

CANDY_NAMESPACE_BEGIN

// �f�o�b�O�E�B���h�E�ւ̏o��
void LogImpl::OutputDebugLog(const char* const _fmt, ...)
{
	va_list args;
	va_start(args, _fmt);
	char buf[4096];
	vsprintf(buf, _fmt, args);
	va_end(args);
	::OutputDebugString(buf);
	::OutputDebugString("\n");
}

CANDY_NAMESPACE_END
