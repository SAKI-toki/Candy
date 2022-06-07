#ifndef CANDY_FORCE_INCLUDE_H
#define CANDY_FORCE_INCLUDE_H

#define _CRT_SECURE_NO_WARNINGS

#define CANDY_NAMESPACE_NAME candy

#define CANDY_NAMESPACE_BEGIN namespace CANDY_NAMESPACE_NAME{
#define CANDY_NAMESPACE_END }

#define CANDY_DO_WHILE_BEGIN do{
#define CANDY_DO_WHILE_END }while(false)

#define CANDY_UNUSED_VALUE(VALUE) static_cast<void>(VALUE)

inline void dummyFunc(...) {}

#include <utility>
#include <cstdint>
#include <memory>
#include <type_traits>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <functional>
#include <filesystem>
#include <fstream>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cassert>

#include "BuildConfig/BuildConfig.h"
#include "Platform/Platform.h"

#include <Type/ArithmetricType.h>
#include <Type/ClassDefine.h>
#include <Debug/Assert/Assert.h>
#include <Debug/Log/Log.h>
#include <Vec/Vec4.h>
#include <Rect/Rect.h>
#include <Color/Color.h>
#include <Setting.h>
#include <Utility/Utility.h>
#include <Global/Global.h>

#endif // CANDY_FORCE_INCLUDE_H
