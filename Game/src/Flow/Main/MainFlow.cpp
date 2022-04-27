#include "MainFlow.h"
#include <Flow/Game/GameFlow.h>
#include <Hardware/Hardware.h>
#include <Graphic/Graphic.h>
#include <FileSystem/FileSystem.h>

CANDY_NAMESPACE_BEGIN

namespace MainFlow
{
}

void MainFlow::Startup()
{
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
}

void MainFlow::Update()
{
	Global::Update();
	Hardware::Update();
	GameFlow::Update();
	Graphic::Update();

	Graphic::DrawBegin();
	GameFlow::Draw();
	Graphic::DrawEnd();
}

bool MainFlow::IsEnd()
{
	return Hardware::IsClose();
}

CANDY_NAMESPACE_END

