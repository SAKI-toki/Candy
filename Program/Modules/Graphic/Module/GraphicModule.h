/*****************************************************************//**
 * \file   GraphicModule.h
 * \brief  Graphicのモジュール
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_GRAPHIC_MODULE_H
#define CANDY_GRAPHIC_MODULE_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Module : public core::ModuleBase
{
	// 他モジュールに依存しない初期化の実装部
	void initializeImpl()override;
	// 他モジュールに依存する初期化の実装部
	void startupImpl()override;
	// 他モジュールに依存する破棄の実装部
	void cleanupImpl()override;
	// 他モジュールに依存しない破棄の実装部
	void releaseImpl()override;

	// 前更新の実装部
	void preUpdateImpl()override;
	// 更新の実装部
	void updateImpl()override;
	// 後更新の実装部
	void postUpdateImpl()override;
	// 前描画の実装部
	void preDrawImpl()override;
	// 描画の実装部
	void drawImpl()override;
	// 後描画の実装部
	void postDrawImpl()override;

	// フリップの実装部
	void flipImpl()override;
};

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_MODULE_H
