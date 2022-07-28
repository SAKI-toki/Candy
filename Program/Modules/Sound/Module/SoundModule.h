/*****************************************************************//**
 * \file   SoundModule.h
 * \brief  Soundのモジュール
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_SOUND_MODULE_H
#define CANDY_SOUND_MODULE_H

#include <Sound/SoundInclude.h>

CANDY_SOUND_NAMESPACE_BEGIN

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

	// フリップの実装部
	void flipImpl()override;
};

CANDY_SOUND_NAMESPACE_END

#endif // CANDY_SOUND_MODULE_H
