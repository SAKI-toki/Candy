/*****************************************************************//**
 * \file   CriticalSection.h
 * \brief  クリティカルセクション
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CORE_CRITICAL_SECTION_H
#define CANDY_CORE_CRITICAL_SECTION_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Mutex/CriticalSectionImpl.h>
#endif

CANDY_CORE_NAMESPACE_BEGIN

class CriticalSection : CriticalSectionImpl
{
public:
	CANDY_DEFAULT_CONSTRUCTOR_DESTRUCTOR(CriticalSection);
	CANDY_DELETE_COPY_MOVE(CriticalSection);

	// 初期化
	void startup();
	// 破棄
	void cleanup();
	// 開始
	void enter();
	// 終了
	void leave();
};

struct ScopeCriticalSection
{
	ScopeCriticalSection(CriticalSection& criticalSection) :m_CriticalSection{ criticalSection } { m_CriticalSection.enter(); }
	~ScopeCriticalSection() { m_CriticalSection.leave(); }
private:
	CriticalSection& m_CriticalSection;
};

#define CANDY_CRITICAL_SECTION_SCOPE_LOCAL_VARIABLE(cs, name) candy::core::ScopeCriticalSection name{ cs }
#define CANDY_CRITICAL_SECTION_SCOPE(cs) CANDY_CRITICAL_SECTION_SCOPE_LOCAL_VARIABLE((cs), _criticalSectionScoleLocalVariable)

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_CRITICAL_SECTION_H
