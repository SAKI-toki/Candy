/*****************************************************************//**
 * \file   Core.h
 * \brief  Coreファイルのインクルード
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_CORE_H
#define CANDY_CORE_H

#include "CoreInclude.h"

#include "BuildConfig/BuildConfig.h"

#include "Color/Color.h"
#include "Color/ConvColor.h"

#include "Config/CoreConfig.h"

#include "Debug/Assert/Assert.h"
#include "Debug/Log/Log.h"

#include "FileSystem/FileSystem.h"
#include "FileSystem/FileEnumerator/FileSystemFileEnumerator.h"
#include "FileSystem/FileInfo/FileSystemFileInfo.h"
#include "FileSystem/Work/FileSystemWork.h"
#include "FileSystem/Work/FileSystemWorkHandle.h"

#include "Handle/Handle.h"
#include "Handle/HandleSystem.h"

#include "Hardware/Hardware.h"

#include "Input/Input.h"
#include "Input/Keyboard/InputKeyboard.h"
#include "Input/Mouse/InputMouse.h"

#include "JobSystem/CoreJobSystem.h"

#include "Library/nameof/nameof.hpp"

#include "Module/CoreModule.h"
#include "Module/CoreModuleBase.h"
#include "Module/CoreModuleManager.h"

#include "Mutex/CriticalSection.h"
#include "Mutex/ThreadEvent.h"

#include "Platform/Platform.h"

#include "Rect/Rect.h"

#include "Std/StdInclude.h"

#include "Thread/ThreadDef.h"
#include "Thread/Thread.h"
#include "Thread/ThreadHandle.h"
#include "Thread/ThreadSystem.h"

#include "Time/Tick.h"
#include "Time/Time.h"

#include "Types/CoreTypes.h"
#include "Types/ClassDefine.h"

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

#endif // CANDY_CORE_H
