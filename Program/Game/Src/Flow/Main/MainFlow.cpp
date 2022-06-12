/*****************************************************************//**
 * \file   MainFlow.cpp
 * \brief  メインフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "MainFlow.h"
#include <Flow/Game/GameFlow.h>
#include <Hardware/Hardware.h>
#include <Graphic/Graphic.h>
#include <FileSystem/FileSystem.h>
#include <Thread/ThreadSystem.h>
#include <Model/Model.h>
#include <Sound/Sound.h>
#include <Font/Font.h>
#include <Debug/Debug.h>
#include <JobSystem/JobSystem.h>

CANDY_NAMESPACE_BEGIN

namespace MainFlow
{
	void UpdateJob();
	void DrawJob();
	JobSystem m_JobSystem;
}

// 初期化
void MainFlow::Startup()
{
	Log::Startup();
	auto threadHandle = ThreadSystem::GetCurrentThreadHandle();
	ThreadSystem::SetThreadNo(threadHandle, 0);
	ThreadSystem::SetPriority(threadHandle, THREAD_PRIORITY::NORMAL);
	Global::Startup();
	FileSystem::Startup();
	Graphic::Startup();
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
	Graphic::Cleanup();
	FileSystem::Cleanup();
	Global::Cleanup();
	Log::Cleanup();
}

// 更新
void MainFlow::Update()
{
	Global::Update();
	Hardware::Update();

	m_JobSystem.execute();
	m_JobSystem.wait();

	Graphic::Flip();
	Global::Flip();
}

// 終了判定
bool MainFlow::IsEnd()
{
	return Hardware::IsClose();
}

// 更新ジョブ
void MainFlow::UpdateJob()
{
	Log::Update();
	GameFlow::Update();
	Graphic::Update();
	Sound::Update();
	Debug::Update();
}

// 描画ジョブ
void MainFlow::DrawJob()
{
	Graphic::PreDraw();
	GameFlow::Draw();
	Model::Primitive::Draw(Graphic::GetCommandList());
	Debug::Draw();
	Graphic::PostDraw();
}

CANDY_NAMESPACE_END

