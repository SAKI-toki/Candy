/*****************************************************************//**
 * \file   EnemyComponent.cpp
 * \brief  敵ビヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "EnemyBehaviorComponent.h"
#include <App/Model/Primitive/ModelPrimitive.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(EnemyBehavior, Base);

	void EnemyBehavior::update()
	{
		base_type::update();

		value = core::LoopStrict(value + Global::GetAppTime() * 100.0f, 0.0f, 300.0f);

		Model::Primitive::AddLine2D(
			Vec4{ 200.0f, 0.0f, 0.0f },
			Vec4{ 200.0f, value, 0.0f },
			5.0f, core::GetColorRGB32(0xff, 0x00, 0x00));
	}
}

CANDY_APP_NAMESPACE_END
