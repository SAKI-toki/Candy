#include "MainFlow.h"
#include <Flow/Game/GameFlow.h>
#include <Hardware/Hardware.h>
#include <Graphic/Graphic.h>

CANDY_NAMESPACE_BEGIN

namespace MainFlow
{
}

void MainFlow::Startup()
{
	Graphic::Startup();
	GameFlow::Startup();
}

void MainFlow::Cleanup()
{
	GameFlow::Cleanup();
	Graphic::Cleanup();
}

void MainFlow::Update()
{
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

