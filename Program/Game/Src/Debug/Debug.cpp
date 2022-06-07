/*****************************************************************//**
 * \file   Debug.cpp
 * \brief  デバッグ関連
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

// 初期化
void Debug::Startup()
{
#if BUILD_DEBUG
	DebugDraw::Startup();
#endif // BUILD_DEBUG
}

// 破棄
void Debug::Cleanup()
{
#if BUILD_DEBUG
	DebugDraw::Cleanup();
#endif // BUILD_DEBUG
}

// 更新
void Debug::Update()
{
#if BUILD_DEBUG
	DebugDraw::Update();
#endif // BUILD_DEBUG
}

// 描画
void Debug::Draw()
{
#if BUILD_DEBUG
	DebugDraw::Draw();
#endif // BUILD_DEBUG
}

CANDY_NAMESPACE_END
