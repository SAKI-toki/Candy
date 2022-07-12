/*****************************************************************//**
 * \file   MainFlow.cpp
 * \brief  メインフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "MainFlow.h"
#include <Flow/Game/GameFlow.h>
#include <Core/Hardware/Hardware.h>
#include <Core/FileSystem/FileSystem.h>
#include <Core/Thread/ThreadSystem.h>
#include <Model/Model.h>
#include <Font/Font.h>
#include <Debug/Debug.h>
#include <JobSystem/JobSystem.h>

namespace MainFlow
{
	void UpdateJob();
	void DrawJob();
	JobSystem m_JobSystem;
}

// 初期化
void MainFlow::Startup()
{
	core::Debug::Log::Startup();
	auto threadHandle = core::ThreadSystem::GetCurrentThreadHandle();
	core::ThreadSystem::SetThreadNo(threadHandle, 0);
	core::ThreadSystem::SetPriority(threadHandle, core::THREAD_PRIORITY::NORMAL);
	Global::Startup();
	core::FileSystem::Startup();
	graphic::GraphicManager::Startup();
	Sound::Startup();
	Model::Startup();
	Font::Startup();
	m_JobSystem.startup(2, 0, 1);
	m_JobSystem.setFunction(UpdateJob);
	m_JobSystem.setFunction(DrawJob);
	Debug::Startup();
	GameFlow::Startup();
}

// 破棄
void MainFlow::Cleanup()
{
	GameFlow::Cleanup();
	Debug::Cleanup();
	m_JobSystem.cleanup();
	Font::Cleanup();
	Model::Cleanup();
	Sound::Cleanup();
	graphic::GraphicManager::Cleanup();
	core::FileSystem::Cleanup();
	Global::Cleanup();
	core::Debug::Log::Cleanup();
}

// 更新
void MainFlow::Update()
{
	Global::Update();
	core::Hardware::Update();

	m_JobSystem.execute();
	m_JobSystem.wait();

	graphic::GraphicManager::Flip();
	Global::Flip();
}

// 終了判定
bool MainFlow::IsEnd()
{
	return core::Hardware::IsClose();
}

// 更新ジョブ
void MainFlow::UpdateJob()
{
	core::Debug::Log::Update();
	GameFlow::Update();
	graphic::GraphicManager::Update();
	Sound::Update();
	Debug::Update();
}

// 描画ジョブ
void MainFlow::DrawJob()
{
	graphic::GraphicManager::PreDraw();
	GameFlow::Draw();
	Model::Primitive::Draw(graphic::GraphicManager::GetCommandList());
	Debug::Draw();
	graphic::GraphicManager::PostDraw();
}
