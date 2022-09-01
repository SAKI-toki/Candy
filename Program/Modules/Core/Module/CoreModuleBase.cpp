/*****************************************************************//**
 * \file   CoreModuleBase.cpp
 * \brief  モジュールの基底
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "CoreModuleBase.h"

CANDY_CORE_NAMESPACE_BEGIN

// 他モジュールに依存しない初期化
void ModuleBase::initialize()
{
	initializeImpl();
}

// 他モジュールに依存する初期化
void ModuleBase::startup()
{
	startupImpl();
}

// 他モジュールに依存する破棄
void ModuleBase::cleanup()
{
	cleanupImpl();
}

// 他モジュールに依存しない破棄
void ModuleBase::release()
{
	releaseImpl();
}

// フレーム開始
void ModuleBase::beginFrame()
{
	beginFrameImpl();
}

// 前更新
void ModuleBase::preUpdate()
{
	preUpdateImpl();
}

// 更新
void ModuleBase::update()
{
	updateImpl();
}

// 後更新
void ModuleBase::postUpdate()
{
	postUpdateImpl();
}

// 前描画登録
void ModuleBase::preRender()
{
	preRenderImpl();
}

// 描画登録
void ModuleBase::render()
{
	renderImpl();
}

// 後描画登録
void ModuleBase::postRender()
{
	postRenderImpl();
}

// 前描画
void ModuleBase::preDraw()
{
	preDrawImpl();
}

// 描画
void ModuleBase::draw()
{
	drawImpl();
}

// 後描画
void ModuleBase::postDraw()
{
	postDrawImpl();
}

// フレーム終了
void ModuleBase::endFrame()
{
	endFrameImpl();
}

// フリップ
void ModuleBase::flip()
{
	flipImpl();
}

CANDY_CORE_NAMESPACE_END
