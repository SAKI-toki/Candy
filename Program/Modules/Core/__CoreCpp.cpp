﻿/*****************************************************************//**
 * \file   __CoreCpp.cpp
 * \brief  Core関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#include "Core.h"

#include "Color/ConvColor.cpp"

#include "Config/CoreConfig.cpp"

#include "Debug/Assert/Assert.cpp"
#include "Debug/Log/Log.cpp"

#include "EntryPoint/Main.cpp"

#include "FileSystem/FileSystem.cpp"
#include "FileSystem/FileEnumerator/FileSystemFileEnumerator.cpp"
#include "FileSystem/FileInfo/FileSystemFileInfo.cpp"
#include "FileSystem/Work/FileSystemWork.cpp"
#include "FileSystem/Work/FileSystemWorkHandle.cpp"

#include "Hardware/Hardware.cpp"

#include "Input/Input.cpp"
#include "Input/Keyboard/InputKeyboard.cpp"
#include "Input/Mouse/InputMouse.cpp"

#include "JobSystem/CoreJobSystem.cpp"

#include "Module/CoreModule.cpp"
#include "Module/CoreModuleBase.cpp"
#include "Module/CoreModuleManager.cpp"

#include "Mutex/CriticalSection.cpp"
#include "Mutex/ThreadEvent.cpp"

#include "Thread/Thread.cpp"
#include "Thread/ThreadHandle.cpp"
#include "Thread/ThreadSystem.cpp"

#include "Time/Tick.cpp"
#include "Time/Time.cpp"

#include "Utility/StringSystem/Convert/StringSystemConvert.cpp"
#include "Utility/StringSystem/Split/StringSystemSplit.cpp"
#include "Utility/Path/Path.cpp"

#include "Vec/Vec4.cpp"
#include "Vec/Vec4Function.cpp"

#if PLATFORM_WIN

#include "Platform/Win/EntryPoint/MainImpl.cpp"

#include "Platform/Win/FileSystem/FileSystemImpl.cpp"
#include "Platform/Win/FileSystem/FileEnumerator/FileSystemFileEnumeratorImpl.cpp"
#include "Platform/Win/FileSystem/FileInfo/FileSystemFileInfoImpl.cpp"

#include "Platform/Win/Hardware/HardwareImpl.cpp"

#include "Platform/Win/Input/Keyboard/InputKeyboardImpl.cpp"
#include "Platform/Win/Input/Mouse/InputMouseImpl.cpp"

#include "Platform/Win/Mutex/CriticalSectionImpl.cpp"
#include "Platform/Win/Mutex/ThreadEventImpl.cpp"

#include "Platform/Win/Utility/StringSystem/Convert/StringSystemConvertImpl.cpp"

#include "Platform/Win/Time/TickImpl.cpp"
#include "Platform/Win/Time/TimeImpl.cpp"

#include "Platform/Win/Thread/ThreadHandleImpl.cpp"
#include "Platform/Win/Thread/ThreadSystemImpl.cpp"

#include "Platform/Win/Vec/Vec4Impl.cpp"
#include "Platform/Win/Vec/Vec4FunctionImpl.cpp"

#endif // PLATFORM_WIN
