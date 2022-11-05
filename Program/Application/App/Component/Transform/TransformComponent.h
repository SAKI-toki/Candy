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

class TransformComponent : public ComponentBase
{
	CANDY_COMPONENT_DECLARE(TransformComponent, ComponentBase);

public:
	const Vec4& getPos()const { return m_Pos; }
	void setPos(const Vec4& _pos) { m_Pos = _pos; m_IsUpdateMatrix = true; }
	void addPos(const Vec4& _add) { m_Pos += _add; m_IsUpdateMatrix = true; }

	const Vec4& getRot()const { return m_Rot; }
	void setRot(const Vec4& _rot) { m_Rot = _rot; m_IsUpdateMatrix = true; }
	void addRot(const Vec4& _add) { m_Rot += _add; m_IsUpdateMatrix = true; }

	const Vec4& getScale()const { return m_Scale; }
	void setScale(const Vec4& _scale) { m_Scale = _scale; m_IsUpdateMatrix = true; }
	void addScale(const Vec4& _add) { m_Scale += _add; m_IsUpdateMatrix = true; }

	void updateMatrix();

private:
	Vec4 m_Pos{};
	Vec4 m_Rot{};
	Vec4 m_Scale{ OneVector };

	bool m_IsUpdateMatrix = false;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_TRANSFORM_COMPONENT_H
