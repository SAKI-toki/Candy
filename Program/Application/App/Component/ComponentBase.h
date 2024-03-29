﻿/*****************************************************************//**
 * \file   ComponentBase.h
 * \brief  コンポーネントの基底
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_COMPONENT_BASE_H
#define CANDY_APP_COMPONENT_BASE_H

#include <App/AppInclude.h>
#include "ComponentDef.h"

CANDY_APP_NAMESPACE_BEGIN

class Entity;

class TransformComponent;

enum class COMPONENT_STATUS_FLAG
{

};

class ComponentBase : public ComponentInterface
{
	CANDY_COMPONENT_DECLARE(ComponentBase, ComponentInterface);

public:
	// 他コンポーネントに依存しない初期化
	void initialize();
	// 他コンポーネントに依存する初期化
	void startup();
	// 破棄
	void cleanup();

	// 前更新
	void preUpdate();
	// 更新
	void update();
	// 後更新
	void postUpdate();

	// 前描画登録
	void preRender();
	// 描画登録
	void render();
	// 後描画登録
	void postRender();

	void setOwnerEntity(const std::weak_ptr<Entity>& _ownerEntity) { m_OwnerEntity = _ownerEntity; }
	std::weak_ptr<Entity> getOwnerEntity()const { return m_OwnerEntity; }

protected:
	// 他コンポーネントに依存しない初期化の実装部
	void initializeImpl() {}
	// 他コンポーネントに依存する初期化の実装部
	virtual void startupImpl() {}
	// 破棄の実装部
	virtual void cleanupImpl() {}

	// 前更新の実装部
	virtual void preUpdateImpl() {}
	// 更新の実装部
	virtual void updateImpl() {}
	// 後更新の実装部
	virtual void postUpdateImpl() {}

	// 前描画登録の実装部
	virtual void preRenderImpl() {}
	// 描画登録の実装部
	virtual void renderImpl() {}
	// 後描画登録の実装部
	virtual void postRenderImpl() {}

	// コンポーネントの取得
	template<typename T, IsBaseComponentComponentInterfaceT<T> = nullptr>
	std::weak_ptr<T> getComponent();
	// コンポーネントの取得
	template<typename T, IsBaseComponentComponentInterfaceT<T> = nullptr>
	const std::weak_ptr<T> getComponent()const;

	// Transformコンポーネントの取得
	std::weak_ptr<TransformComponent> getTransformComponent();
	const std::weak_ptr<TransformComponent> getTransformComponent()const;

	std::weak_ptr<Entity> m_OwnerEntity;
};

CANDY_APP_NAMESPACE_END

#include "ComponentBase.inl"

#endif // CANDY_APP_COMPONENT_BASE_H
