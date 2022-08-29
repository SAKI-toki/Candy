/*****************************************************************//**
 * \file   ComponentBase.h
 * \brief  コンポーネントの基底
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_BASE_H
#define CANDY_APP_COMPONENT_BASE_H

#include <App/AppInclude.h>
#include "ComponentDef.h"
#include <App/Entity/Entity.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Component
{
	class Base : public Interface
	{
		CANDY_COMPONENT_DECLARE(Base, Interface);

	public:
		// 初期化
		virtual void startup();
		// 破棄
		virtual void cleanup();

		// 前更新
		virtual void preUpdate();
		// 更新
		virtual void update();
		// 後更新
		virtual void postUpdate();

		void setOwnerEntityHandle(const EntityHandle _handle) { m_OwnerEntityHandle = _handle; }

	protected:
		EntityHandle m_OwnerEntityHandle;
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_COMPONENT_BASE_H
