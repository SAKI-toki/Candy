/*****************************************************************//**
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
	// 前更新
	void preUpdate();
	// 更新
	void update();
	// 後更新
	void postUpdate();
	// 前描画
	void preDraw();
	// 描画
	void draw();
	// 後描画
	void postDraw();
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
	// 前更新の実装部
	virtual void preUpdateImpl() {}
	// 更新の実装部
	virtual void updateImpl() {}
	// 後更新の実装部
	virtual void postUpdateImpl() {}
	// 前描画の実装部
	virtual void preDrawImpl() {}
	// 描画の実装部
	virtual void drawImpl() {}
	// 後描画の実装部
	virtual void postDrawImpl() {}
	// フレーム終了の実装部
	virtual void endFrameImpl() {}

	// フリップの実装部
	virtual void flipImpl() {}
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MODULE_BASE_H
