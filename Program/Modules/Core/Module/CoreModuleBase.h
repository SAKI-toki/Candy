﻿/*****************************************************************//**
 * \file   CoreModuleBase.h
 * \brief  モジュールの基底
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_CORE_MODULE_BASE_H
#define CANDY_CORE_MODULE_BASE_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

class ModuleBase
{
public:
	// 他モジュールに依存しない初期化
	void initialize();
	// 他モジュールに依存する初期化
	void startup();
	// 他モジュールに依存する破棄
	void cleanup();
	// 他モジュールに依存しない破棄
	void release();

	// フレーム開始
	void beginFrame();

	// 更新開始
	void beginUpdate();
	// 前更新
	void preUpdate();
	// 更新
	void update();
	// 後更新
	void postUpdate();
	// 更新終了
	void endUpdate();

	// 描画登録開始
	void beginRender();
	// 前描画登録
	void preRender();
	// 描画登録
	void render();
	// 後描画登録
	void postRender();
	// 描画登録終了
	void endRender();

	// 描画開始
	void beginDraw();
	// 前描画
	void preDraw();
	// 描画
	void draw();
	// 後描画
	void postDraw();
	// 描画終了
	void endDraw();

	// フレーム終了
	void endFrame();

	// フリップ
	void flip();

protected:
	// 他モジュールに依存しない初期化の実装部
	virtual void initializeImpl() {}
	// 他モジュールに依存する初期化の実装部
	virtual void startupImpl() {}
	// 他モジュールに依存する破棄の実装部
	virtual void cleanupImpl() {}
	// 他モジュールに依存しない破棄の実装部
	virtual void releaseImpl() {}

	// フレーム開始の実装部
	virtual void beginFrameImpl() {}

	// 更新開始の実装部
	virtual void beginUpdateImpl() {}
	// 前更新の実装部
	virtual void preUpdateImpl() {}
	// 更新の実装部
	virtual void updateImpl() {}
	// 後更新の実装部
	virtual void postUpdateImpl() {}
	// 更新終了の実装部
	virtual void endUpdateImpl() {}

	// 更新開始の実装部
	virtual void beginRenderImpl() {}
	// 前描画登録の実装部
	virtual void preRenderImpl() {}
	// 描画登録の実装部
	virtual void renderImpl() {}
	// 後描画登録の実装部
	virtual void postRenderImpl() {}
	// 描画登録終了の実装部
	virtual void endRenderImpl() {}

	// 描画開始の実装部
	virtual void beginDrawImpl() {}
	// 前描画の実装部
	virtual void preDrawImpl() {}
	// 描画の実装部
	virtual void drawImpl() {}
	// 後描画の実装部
	virtual void postDrawImpl() {}
	// 描画終了の実装部
	virtual void endDrawImpl() {}

	// フレーム終了の実装部
	virtual void endFrameImpl() {}

	// フリップの実装部
	virtual void flipImpl() {}
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MODULE_BASE_H
