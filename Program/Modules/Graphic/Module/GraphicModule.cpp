/*****************************************************************//**
 * \file   GraphicModule.cpp
 * \brief  Graphicのモジュール
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include <Graphic/Module/GraphicModule.h>
#include <Graphic/System/GraphicSystem.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

// 他モジュールに依存しない初期化の実装部
void Module::initializeImpl()
{
	System::Startup();
}

// 他モジュールに依存する初期化の実装部
void Module::startupImpl()
{

}

// 他モジュールに依存する破棄の実装部
void Module::cleanupImpl()
{

}

// 他モジュールに依存しない破棄の実装部
void Module::releaseImpl()
{
	System::Cleanup();
}

// 前更新の実装部
void Module::preUpdateImpl()
{

}

// 更新の実装部
void Module::updateImpl()
{
	System::Update();
}

// 後更新の実装部
void Module::postUpdateImpl()
{

}

// 前描画の実装部
void Module::preDrawImpl()
{
	System::PreDraw();
}

// 描画の実装部
void Module::drawImpl()
{

}

// 後描画の実装部
void Module::postDrawImpl()
{
	System::PostDraw();
}

// フリップの実装部
void Module::flipImpl()
{
	System::Flip();
}

CANDY_GRAPHIC_NAMESPACE_END
