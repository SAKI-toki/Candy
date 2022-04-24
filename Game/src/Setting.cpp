#include "Setting.h"

CANDY_NAMESPACE_BEGIN

const char* Setting::GetAppName()
{
	return "Candy";
}

f32 Setting::GetMaxAppTime()
{
	return 1.0f / 30.0f;
}

CANDY_NAMESPACE_END
