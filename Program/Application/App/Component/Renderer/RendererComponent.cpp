/*****************************************************************//**
 * \file   RendererComponent.cpp
 * \brief  レンダラーコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "RendererComponent.h"
#include <App/Debug/Draw/DebugDraw.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	CANDY_COMPONENT_DEFINE(Renderer, Base);

	void Renderer::renderImpl()
	{
		auto transform = m_OwnerEntity->getTransformComponent();
		if (!transform)return;

		auto pos = transform->getPos();
		auto scale = transform->getScale();

		Rect rect;
		rect.setSize(pos.x, pos.y, scale.x, scale.y);
		DebugDraw::Primitive2D::AddRect2D(rect, m_Color);
	}
}

CANDY_APP_NAMESPACE_END
