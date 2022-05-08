#include "MainFlow.h"
#include <Flow/Game/GameFlow.h>
#include <Hardware/Hardware.h>
#include <Graphic/Graphic.h>
#include <FileSystem/FileSystem.h>
#include <Thread/ThreadSystem.h>

CANDY_NAMESPACE_BEGIN

namespace MainFlow
{
}

void MainFlow::Startup()
{
	Log::Startup();
	auto threadHandle = ThreadSystem::GetCurrentThreadHandle();
	ThreadSystem::SetThreadNo(threadHandle, 0);
	ThreadSystem::SetPriority(threadHandle, THREAD_PRIORITY::NORMAL);
	Global::Startup();
	FileSystem::Startup();
	Graphic::Startup();
	GameFlow::Startup();
}

void MainFlow::Cleanup()
{
	GameFlow::Cleanup();
	Graphic::Cleanup();
	FileSystem::Cleanup();
	Global::Cleanup();
	Log::Cleanup();
}

void MainFlow::Update()
{
	Log::Update();
	Global::Update();
	Hardware::Update();
	GameFlow::Update();
	Graphic::Update();

	Graphic::PreDraw();
	GameFlow::Draw();
	Graphic::PostDraw();
}

bool MainFlow::IsEnd()
{
	return Hardware::IsClose();
}

CANDY_NAMESPACE_END

