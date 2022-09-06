/*****************************************************************//**
 * \file   DebugDraw.cpp
 * \brief  デバッグ描画
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "DebugDraw.h"

CANDY_APP_NAMESPACE_BEGIN

namespace DebugDraw
{

}

// 初期化
void DebugDraw::Startup()
{
#if BUILD_DEBUG
	Primitive2D::Startup();
	String::Startup();
#endif // BUILD_DEBUG
}

// 破棄
void DebugDraw::Cleanup()
{
#if BUILD_DEBUG
	Primitive2D::Cleanup();
	String::Cleanup();
#endif // BUILD_DEBUG
}

// 更新
void DebugDraw::Update()
{
#if BUILD_DEBUG
	Primitive2D::Update();
	String::Update();
#endif // BUILD_DEBUG
}

// 描画
void DebugDraw::Draw()
{
#if BUILD_DEBUG
	Primitive2D::Draw();
	String::Draw();
#endif // BUILD_DEBUG
}

CANDY_APP_NAMESPACE_END
