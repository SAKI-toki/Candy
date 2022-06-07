/*****************************************************************//**
 * \file   Model.h
 * \brief  モデル
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_MODEL_H
#define CANDY_MODEL_H

#include "Primitive/ModelPrimitive.h"

CANDY_NAMESPACE_BEGIN

namespace Model
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
}

CANDY_NAMESPACE_END

#endif // CANDY_MODEL_H
