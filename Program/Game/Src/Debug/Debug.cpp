/*****************************************************************//**
 * \file   Debug.cpp
 * \brief  �f�o�b�O�֘A
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/
#include "Debug.h"
#include "Draw/DebugDraw.h"

CANDY_NAMESPACE_BEGIN

namespace Debug
{
#if BUILD_DEBUG


#endif // BUILD_DEBUG
}

// ������
void Debug::Startup()
{
#if BUILD_DEBUG
	DebugDraw::Startup();
#endif // BUILD_DEBUG
}

// �j��
void Debug::Cleanup()
{
#if BUILD_DEBUG
	DebugDraw::Cleanup();
#endif // BUILD_DEBUG
}

// �X�V
void Debug::Update()
{
#if BUILD_DEBUG
	DebugDraw::Update();
#endif // BUILD_DEBUG
}

// �`��
void Debug::Draw()
{
#if BUILD_DEBUG
	DebugDraw::Draw();
#endif // BUILD_DEBUG
}

CANDY_NAMESPACE_END
