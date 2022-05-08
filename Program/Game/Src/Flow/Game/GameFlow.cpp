#include "GameFlow.h"
#include <Flow/Scene/SceneFlow.h>
#include <Input/Input.h>

CANDY_NAMESPACE_BEGIN

namespace GameFlow
{
}

void GameFlow::Startup()
{
	Input::Startup();
}

void GameFlow::Cleanup()
{
	Input::Cleanup();
}

void GameFlow::Update()
{
	Input::Update();
}

void GameFlow::Draw()
{

}

CANDY_NAMESPACE_END

