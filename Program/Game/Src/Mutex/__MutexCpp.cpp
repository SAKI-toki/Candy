/*****************************************************************//**
 * \file   __MutexCpp.cpp
 * \brief  �~���[�e�b�N�X�֘A��cpp�t�@�C������
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "CriticalSection.cpp"

#if PLATFORM_WIN
#include "Platform/Win/CriticalSectionImpl.cpp"
#endif
