/*****************************************************************//**
 * \file   LogImpl.h
 * \brief  �f�o�b�O���O�̎�����(Win)
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/
#ifndef CANDY_DEBUG_LOG_IMPL_H
#define CANDY_DEBUG_LOG_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace LogImpl
{
	// �f�o�b�O�E�B���h�E�ւ̏o��
	void OutputDebugLog(const char* const _fmt, ...);
}

CANDY_NAMESPACE_END

#endif // CANDY_DEBUG_LOG_IMPL_H
