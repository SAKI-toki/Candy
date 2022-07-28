/*****************************************************************//**
 * \file   SoundModule.cpp
 * \brief  Soundのモジュール
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include <Sound/Module/SoundModule.h>
#include <Sound/System/SoundSystem.h>

CANDY_SOUND_NAMESPACE_BEGIN

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

// フリップの実装部
void Module::flipImpl()
{

}

CANDY_SOUND_NAMESPACE_END
