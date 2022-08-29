/*****************************************************************//**
 * \file   ComponentBase.cpp
 * \brief  コンポーネントの基底
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentBase.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(Base, Interface);

	// 初期化
	void Base::startup()
	{

	}

	// 破棄
	void Base::cleanup()
	{

	}

	// 前更新
	void Base::preUpdate()
	{

	}

	// 更新
	void Base::update()
	{

	}

	// 後更新
	void Base::postUpdate()
	{

	}
}

CANDY_APP_NAMESPACE_END
