/*****************************************************************//**
 * \file   ComponentBase.cpp
 * \brief  コンポーネントの基底
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#include "ComponentBase.h"
#include "Transform/TransformComponent.h"

CANDY_APP_NAMESPACE_BEGIN

CANDY_COMPONENT_DEFINE(ComponentBase, ComponentInterface);

// 他コンポーネントに依存しない初期化
void ComponentBase::initialize()
{
	initializeImpl();
}

// 他コンポーネントに依存する初期化
void ComponentBase::startup()
{
	startupImpl();
}

// 破棄
void ComponentBase::cleanup()
{
	cleanupImpl();
}

// 前更新
void ComponentBase::preUpdate()
{
	preUpdateImpl();
}

// 更新
void ComponentBase::update()
{
	updateImpl();
}

// 後更新
void ComponentBase::postUpdate()
{
	postUpdateImpl();
}

// 前描画登録
void ComponentBase::preRender()
{
	preRenderImpl();
}

// 描画登録
void ComponentBase::render()
{
	renderImpl();
}

// 後描画登録
void ComponentBase::postRender()
{
	postRenderImpl();
}


// Transformコンポーネントの取得
std::weak_ptr<TransformComponent> ComponentBase::getTransformComponent()
{
	return getComponent<TransformComponent>();
}

// Transformコンポーネントの取得
const std::weak_ptr<TransformComponent> ComponentBase::getTransformComponent()const
{
	return getComponent<TransformComponent>();
}

CANDY_APP_NAMESPACE_END
