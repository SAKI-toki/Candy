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
	if (Input::IsKeyOn('V'))Model::Primitive::AddTriangle2D(Vec4{  0.5f,  0.5f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0xff));
	if (Input::IsKeyOn('B'))Model::Primitive::AddTriangle2D(Vec4{  0.5f, -0.5f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0xff));
	if (Input::IsKeyOn('N'))Model::Primitive::AddTriangle2D(Vec4{ -0.5f,  0.5f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0xff));
	if (Input::IsKeyOn('M'))Model::Primitive::AddTriangle2D(Vec4{ -0.5f, -0.5f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0xff));
}

void GameFlow::Draw()
{

}

CANDY_NAMESPACE_END

