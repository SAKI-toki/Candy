#ifndef CANDY_GLOBAL_H
#define CANDY_GLOBAL_H

CANDY_NAMESPACE_BEGIN

namespace Global
{
	void Startup();
	void Cleanup();
	void Update();

	f32 GetAppTime();
	f32 GetAppTimeAll();
}

CANDY_NAMESPACE_END

#endif // CANDY_GLOBAL_H
