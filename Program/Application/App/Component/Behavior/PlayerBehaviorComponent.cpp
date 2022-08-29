/*****************************************************************//**
 * \file   PlayerBehaviorComponent.cpp
 * \brief  プレイヤービヘイビアコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "PlayerBehaviorComponent.h"
#include <App/Model/Primitive/ModelPrimitive.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(PlayerBehavior, Base);

	void PlayerBehavior::update()
	{
		base_type::update();

		value += Global::GetAppTime() * 0.3f;

		Model::Primitive::AddLine2D(
			Vec4{ 400.0f, 200.0f, 0.0f },
			Vec4{ 400.0f, 200.0f + std::sinf(value) * 50.0f, 0.0f },
			5.0f, core::GetColorRGB32(0x00, 0xff, 0x00));
	}
}

CANDY_APP_NAMESPACE_END
