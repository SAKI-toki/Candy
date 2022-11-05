/*****************************************************************//**
 * \file   ModelManager.h
 * \brief  モデルの管理
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_MODEL_MANAGER_H
#define CANDY_MODEL_MANAGER_H

#include <App/AppInclude.h>

#include "Primitive/ModelPrimitive.h"

CANDY_APP_NAMESPACE_BEGIN

namespace ModelManager
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_MODEL_MANAGER_H
