#ifndef CANDY_CRITICAL_SECTION_H
#define CANDY_CRITICAL_SECTION_H

#if PLATFORM_WIN
#include "Platform/Win/CriticalSectionImpl.h"
#endif

CANDY_NAMESPACE_BEGIN

class CriticalSection : CriticalSectionImpl
{
public:

	DEFAULT_CONSTRUCTOR_DESTRUCTOR_DELETE_COPY_MOVE(CriticalSection);

	void startup();
	void cleanup();
	void enter();
	void leave();
};

struct ScopeCriticalSection
{
	ScopeCriticalSection(CriticalSection& criticalSection) :m_CriticalSection{ criticalSection } { m_CriticalSection.enter(); }
	~ScopeCriticalSection() { m_CriticalSection.leave(); }
private:
	CriticalSection& m_CriticalSection;
};

#define CANDY_CRITICAL_SECTION_SCOPE_LOCAL_VARIABLE(cs, name) CANDY_NAMESPACE_NAME::ScopeCriticalSection name{ cs }
#define CANDY_CRITICAL_SECTION_SCOPE(cs) CANDY_CRITICAL_SECTION_SCOPE_LOCAL_VARIABLE((cs), _criticalSectionScoleLocalVariable)

CANDY_NAMESPACE_END

#endif // CANDY_CRITICAL_SECTION_H
