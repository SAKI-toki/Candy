/*****************************************************************//**
 * \file   RendererComponent.h
 * \brief  レンダラーコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_RENDERER_COMPONENT_H
#define CANDY_APP_RENDERER_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class Renderer : public Base
	{
		CANDY_COMPONENT_DECLARE(Renderer, Base);

	public:
		void renderImpl()override;

		void setColor(const Color& _color) { m_Color = _color; }
		const Color& getColor()const { return m_Color; }

	private:
		Color m_Color{ OneVector };
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_RENDERER_COMPONENT_H
