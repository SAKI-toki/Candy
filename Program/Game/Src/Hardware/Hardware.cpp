/*****************************************************************//**
 * \file   Hardware.cpp
 * \brief  �n�[�h�E�F�A
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Hardware.h"

CANDY_NAMESPACE_BEGIN

// ������
void Hardware::Startup(const StartupInfo& _startupInfo)
{
	Impl::Startup(_startupInfo);
}

// �j��
void Hardware::Cleanup()
{
	Impl::Cleanup();
}

// �X�V
void Hardware::Update()
{
	Impl::Update();
}

// ������
bool Hardware::IsClose()
{
	return Impl::IsClose();
}

CANDY_NAMESPACE_END
