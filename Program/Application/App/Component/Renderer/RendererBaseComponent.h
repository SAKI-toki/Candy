/*****************************************************************//**
 * \file   RendererBaseComponent.h
 * \brief  レンダラーのベースコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_RENDERER_BASE_COMPONENT_H
#define CANDY_APP_RENDERER_BASE_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class RendererBase : public ComponentBase
	{
		CANDY_COMPONENT_DECLARE(RendererBase, ComponentBase);

	public:
		void setColor(const Color& _color) { m_Color = _color; }
		const Color& getColor()const { return m_Color; }

	private:
		Color m_Color{ WhiteColor };
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_RENDERER_BASE_COMPONENT_H
