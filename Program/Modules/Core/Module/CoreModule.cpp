/*****************************************************************//**
 * \file   CoreModule.cpp
 * \brief  Coreのモジュール
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include <Core/Module/CoreModule.h>
#include <Core/Thread/ThreadSystem.h>
#include <Core/FileSystem/FileSystem.h>
#include <Core/Hardware/Hardware.h>
#include <Core/Time/Time.h>

CANDY_CORE_NAMESPACE_BEGIN

// 他モジュールに依存しない初期化の実装部
void Module::initializeImpl()
{
	Debug::Log::Startup();
	auto threadHandle = ThreadSystem::GetCurrentThreadHandle();
	ThreadSystem::SetThreadNo(threadHandle, 0);
	ThreadSystem::SetPriority(threadHandle, THREAD_PRIORITY::NORMAL);
	FileSystem::Startup();
	Time::Startup();
	Input::Startup();
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
	core::Input::Cleanup();
	Time::Cleanup();
	FileSystem::Cleanup();
	Debug::Log::Cleanup();
}

// フレーム開始の実装部
void Module::beginFrameImpl()
{
	Hardware::Update();
	core::Input::Update();
}

// 前更新の実装部
void Module::preUpdateImpl()
{
	Debug::Log::Update();
}

// 更新の実装部
void Module::updateImpl()
{

}

// 後更新の実装部
void Module::postUpdateImpl()
{

}

// フレーム終了の実装部
void Module::endFrameImpl()
{

}

// フリップの実装部
void Module::flipImpl()
{
	System::Flip();
}

CANDY_CORE_NAMESPACE_END
