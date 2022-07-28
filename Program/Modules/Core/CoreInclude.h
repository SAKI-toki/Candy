/*****************************************************************//**
 * \file   CoreInclude.h
 * \brief  Coreのインクルードファイル
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_CORE_INCLUDE_H
#define CANDY_CORE_INCLUDE_H

#define CANDY_NAMESPACE_NAME candy

#define CANDY_NAMESPACE_BEGIN namespace CANDY_NAMESPACE_NAME{
#define CANDY_NAMESPACE_END }

#define CANDY_CORE_NAMESPACE_NAME core

#define CANDY_CORE_NAMESPACE_BEGIN CANDY_NAMESPACE_BEGIN namespace CANDY_CORE_NAMESPACE_NAME{
#define CANDY_CORE_NAMESPACE_END } CANDY_NAMESPACE_END

#define CANDY_DO_WHILE_BEGIN do{
#define CANDY_DO_WHILE_END }while(false)

#define CANDY_UNUSED_VALUE(VALUE) static_cast<void>(VALUE)

inline void DummyFunc(...) {}

#include "Std/StdInclude.h"
#include "BuildConfig/BuildConfig.h"
#include "Types/ClassDefine.h"
#include "Platform/Platform.h"
#include "Types/CoreTypes.h"
#include "Config/CoreConfig.h"

#include "Debug/Assert/Assert.h"
#include "Debug/Log/Log.h"

#include "Library/nameof/nameof.hpp"

#include "Utility/ArraySize/ArraySize.h"
#include "Utility/Clamp/Clamp.h"
#include "Utility/Endian/Endian.h"
#include "Utility/Hash/Hash.h"
#include "Utility/Loop/Loop.h"
#include "Utility/MinMax/MinMax.h"
#include "Utility/Path/Path.h"
#include "Utility/StaticVector/StaticVector.h"
#include "Utility/StringSystem/Convert/StringSystemConvert.h"
#include "Utility/StringSystem/Split/StringSystemSplit.h"
#include "Utility/StringSystem/UpperLower/StringSystemToUpperLower.h"
#include "Vec/Vec4.h"
#include "Color/Color.h"
#include "Color/ConvColor.h"

#endif // CANDY_CORE_INCLUDE_H
