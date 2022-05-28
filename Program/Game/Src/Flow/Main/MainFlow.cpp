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
	Sound::Startup();
	Model::Startup();
	Font::Startup();
	Debug::Startup();
	GameFlow::Startup();
}

void MainFlow::Cleanup()
{
	GameFlow::Cleanup();
	Debug::Cleanup();
	Font::Cleanup();
	Model::Cleanup();
	Sound::Cleanup();
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
	Sound::Update();
	Debug::Update();

	Graphic::PreDraw();
	GameFlow::Draw();
	Model::Primitive::Draw(Graphic::GetCommandList());
	Debug::Draw();
	Graphic::PostDraw();
	Graphic::Flip();
}

bool MainFlow::IsEnd()
{
	return Hardware::IsClose();
}

CANDY_NAMESPACE_END

