#include "Setting.h"

CANDY_NAMESPACE_BEGIN

namespace Setting
{
#define CANDY_BASE_PATH R"(D:\Candy\)"
#define CANDY_DATA_PATH CANDY_BASE_PATH R"(\Data\Win\)"
}

const char* Setting::GetAppName()
{
	return "Candy";
}

f32 Setting::GetMaxAppTime()
{
	return 1.0f / 30.0f;
}

const char* Setting::GetBasePath()
{
	return CANDY_BASE_PATH;
}

const char* Setting::GetDataPath()
{
	return CANDY_DATA_PATH;
}

CANDY_NAMESPACE_END
