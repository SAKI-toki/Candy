#ifndef CANDY_INPUT_H
#define CANDY_INPUT_H

CANDY_NAMESPACE_BEGIN

namespace Input
{
	void Startup();
	void Cleanup();

	void Update();

	bool IsKeyTrigger(const u8 _key);
	bool IsKeyOn(const u8 _key);
	bool IsKeyRelease(const u8 _key);
	bool IsKeyRepeat(const u8 _key);

	Vec4 GetScreenMousePos();
	Vec4 GetClientMousePos();
	Vec4 GetPrevScreenMousePos();
	Vec4 GetPrevClientMousePos();
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_H
