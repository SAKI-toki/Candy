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

	// 他コンポーネントに依存しない初期化
	void Base::initialize()
	{
		initializeImpl();
	}

	// 他コンポーネントに依存する初期化
	void Base::startup()
	{
		startupImpl();
	}

	// 破棄
	void Base::cleanup()
	{
		cleanupImpl();
	}

	// 前更新
	void Base::preUpdate()
	{
		preUpdateImpl();
	}

	// 更新
	void Base::update()
	{
		updateImpl();
	}

	// 後更新
	void Base::postUpdate()
	{
		postUpdateImpl();
	}

	// 前描画登録
	void Base::preRender()
	{
		preRenderImpl();
	}

	// 描画登録
	void Base::render()
	{
		renderImpl();
	}

	// 後描画登録
	void Base::postRender()
	{
		postRenderImpl();
	}
}

CANDY_APP_NAMESPACE_END
