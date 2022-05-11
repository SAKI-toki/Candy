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
	if (Input::IsKeyOn('C'))Model::Primitive::AddRect2D(Rect{ -0.5f,0.0f, 1.0f, 1.0f }, CANDY_COLOR_RGBA32(0xff, 0x00, 0xff, 0x80));
	if (Input::IsKeyOn('V'))Model::Primitive::AddRect2D(Vec4{  0.5f,  0.5f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0xff, 0x00));
	if (Input::IsKeyOn('B'))Model::Primitive::AddRect2D(Vec4{  0.5f,  0.5f, 0.0f }, CANDY_COLOR_RGB32(0xff, 0x00, 0xff));
	if (Input::IsKeyOn('N'))Model::Primitive::AddRect2D(Vec4{  0.5f,  0.5f, 0.0f }, CANDY_COLOR_RGB32(0x00, 0xff, 0xff));
	if (Input::IsKeyOn('M'))Model::Primitive::AddRect2D(Vec4{  0.5f,  0.5f, 0.0f }, CANDY_COLOR_RGBA32(0xff, 0x00, 0xff, 0x80));
}

void GameFlow::Draw()
{

}

CANDY_NAMESPACE_END

