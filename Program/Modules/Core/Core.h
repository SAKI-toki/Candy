/*****************************************************************//**
 * \file   Core.h
 * \brief  Coreファイルのインクルード
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_CORE_H
#define CANDY_CORE_H

#include "CoreInclude.h"

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

#include "Mutex/CriticalSection.h"
#include "Mutex/ThreadEvent.h"

#include "Rect/Rect.h"

#include "Thread/ThreadDef.h"
#include "Thread/Thread.h"
#include "Thread/ThreadHandle.h"
#include "Thread/ThreadSystem.h"

#include "Time/Tick.h"
#include "Time/Time.h"


#endif // CANDY_CORE_H
