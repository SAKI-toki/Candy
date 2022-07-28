/*****************************************************************//**
 * \file   CoreModuleManager.h
 * \brief  モジュールの管理クラス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_CORE_MODULE_MANAGER_H
#define CANDY_CORE_MODULE_MANAGER_H

#include <Core/CoreInclude.h>
#include "CoreModuleBase.h"
#include <Core/JobSystem/CoreJobSystem.h>

CANDY_CORE_NAMESPACE_BEGIN

class ModuleManager
{
public:
	// 初期化(coreは最初に追加する)
	void startup(std::unique_ptr<ModuleBase>&& _coreModule);
	// 破棄
	void cleanup();
	// 更新
	void update();
	// フリップ
	void flip();

	// モジュールの初期化
	void startupModule();
	// モジュールの破棄
	void cleanupModule();

	// モジュールの追加
	void addModule(std::unique_ptr<ModuleBase>&& _module);

private:

	// モジュールの更新
	void updateModule();
	// モジュールの描画
	void drawModule();
	// モジュールのフリップ
	void flipModule();

	// 正順でのモジュール変換
	void transformModuleNormalOrder(void(ModuleBase::*_func)());
	// 逆順でのモジュール変換
	void transformModuleReverseOrder(void(ModuleBase::* _func)());

	std::vector<std::unique_ptr<ModuleBase>> m_Modules;
	std::unique_ptr<ModuleBase> m_CoreModule;
	JobSystem m_JobSystem;
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MODULE_MANAGER_H
