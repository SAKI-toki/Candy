/*****************************************************************//**
 * \file   CoreModuleManager.h
 * \brief  モジュールの管理クラス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "CoreModuleManager.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace ModuleManager
{
	// モジュールの更新
	void updateModule();
	// モジュールの描画
	void drawModule();
	// モジュールのフリップ
	void flipModule();

	// 正順でのモジュール変換
	void transformModuleNormalOrder(void(ModuleBase::* _func)());
	// 逆順でのモジュール変換
	void transformModuleReverseOrder(void(ModuleBase::* _func)());

	std::vector<std::unique_ptr<ModuleBase>> m_Modules;
	std::unique_ptr<ModuleBase> m_CoreModule;
	JobSystem m_JobSystem;
}

// 初期化(coreは最初に追加する)
void ModuleManager::startup(std::unique_ptr<ModuleBase>&& _coreModule)
{
	m_JobSystem.startup(2, 0, 1);
	m_JobSystem.setFunctions({ []() { updateModule(); }, []() { drawModule(); } });

	if (_coreModule)
	{
		m_CoreModule = std::move(_coreModule);
		m_CoreModule->initialize();
	}
}

// 破棄
void ModuleManager::cleanup()
{
	m_Modules.clear();
	m_CoreModule.reset();

	m_JobSystem.cleanup();
}

// 更新
void ModuleManager::update()
{
	transformModuleNormalOrder(&ModuleBase::beginFrame);
	m_JobSystem.execute();
	m_JobSystem.wait();
	transformModuleReverseOrder(&ModuleBase::endFrame);
}

// フリップ
void ModuleManager::flip()
{
	flipModule();
}

// モジュールの初期化
void ModuleManager::startupModule()
{
	transformModuleNormalOrder(&ModuleBase::startup);
}

// モジュールの破棄
void ModuleManager::cleanupModule()
{
	transformModuleReverseOrder(&ModuleBase::cleanup);
	transformModuleReverseOrder(&ModuleBase::release);
}

// モジュールの更新
void ModuleManager::updateModule()
{
	transformModuleNormalOrder(&ModuleBase::preUpdate);
	transformModuleNormalOrder(&ModuleBase::update);
	transformModuleNormalOrder(&ModuleBase::postUpdate);
	transformModuleNormalOrder(&ModuleBase::preRender);
	transformModuleNormalOrder(&ModuleBase::render);
	transformModuleNormalOrder(&ModuleBase::postRender);
}

// モジュールの描画
void ModuleManager::drawModule()
{
	transformModuleNormalOrder(&ModuleBase::preDraw);
	transformModuleNormalOrder(&ModuleBase::draw);
	transformModuleNormalOrder(&ModuleBase::postDraw);
}

// モジュールのフリップ
void ModuleManager::flipModule()
{
	transformModuleNormalOrder(&ModuleBase::flip);
}

// モジュールの追加
void ModuleManager::addModule(std::unique_ptr<ModuleBase>&& _module)
{
	if (!_module)return;

	_module->initialize();
	m_Modules.push_back(std::move(_module));
}

// 正順でのモジュール変換
void ModuleManager::transformModuleNormalOrder(void(ModuleBase::* _func)())
{
	if (!_func)return;

	if (m_CoreModule)(m_CoreModule.get()->*_func)();
	std::for_each(m_Modules.begin(), m_Modules.end(),
		[_func](std::unique_ptr<ModuleBase>& m) { if(m)(m.get()->*_func)(); });
}

// 逆順でのモジュール変換
void ModuleManager::transformModuleReverseOrder(void(ModuleBase::* _func)())
{
	if (!_func)return;

	std::for_each(m_Modules.rbegin(), m_Modules.rend(),
		[_func](std::unique_ptr<ModuleBase>& m) { if (m)(m.get()->*_func)(); });
	if (m_CoreModule)(m_CoreModule.get()->*_func)();
}

CANDY_CORE_NAMESPACE_END
