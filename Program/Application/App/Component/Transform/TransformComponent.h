/*****************************************************************//**
 * \file   TransformComponent.h
 * \brief  Transformコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_TRANSFORM_COMPONENT_H
#define CANDY_APP_TRANSFORM_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class Transform : public Base
	{
		CANDY_COMPONENT_DECLARE(Transform, Base);

	public:
		const Vec4& getPos()const { return m_Pos; }
		void setPos(const Vec4& _pos) { m_Pos = _pos; }
		void addPos(const Vec4& _add) { m_Pos += _add; }

		const Vec4& getRot()const { return m_Rot; }
		void setRot(const Vec4& _rot) { m_Rot = _rot; }
		void addRot(const Vec4& _add) { m_Rot += _add; }

		const Vec4& getScale()const { return m_Scale; }
		void setScale(const Vec4& _scale) { m_Scale = _scale; }
		void addScale(const Vec4& _add) { m_Scale += _add; }

	private:
		Vec4 m_Pos{};
		Vec4 m_Rot{};
		Vec4 m_Scale{};
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_TRANSFORM_COMPONENT_H
