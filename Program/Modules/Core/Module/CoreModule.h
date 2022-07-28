/*****************************************************************//**
 * \file   CoreModule.h
 * \brief  Coreのモジュール
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_CORE_MODULE_H
#define CANDY_CORE_MODULE_H

#include <Core/CoreInclude.h>
#include <Core/Module/CoreModuleBase.h>

CANDY_CORE_NAMESPACE_BEGIN

class Module : public ModuleBase
{
	// 他モジュールに依存しない初期化の実装部
	void initializeImpl()override;
	// 他モジュールに依存する初期化の実装部
	void startupImpl()override;
	// 他モジュールに依存する破棄の実装部
	void cleanupImpl()override;
	// 他モジュールに依存しない破棄の実装部
	void releaseImpl()override;

	// フレーム開始の実装部
	void beginFrameImpl()override;
	// 前更新の実装部
	void preUpdateImpl()override;
	// 更新の実装部
	void updateImpl()override;
	// 後更新の実装部
	void postUpdateImpl()override;
	// フレーム終了の実装部
	void endFrameImpl()override;
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MODULE_H
