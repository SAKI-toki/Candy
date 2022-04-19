#ifndef CANDY_CRITICAL_SECTION_IMPL_H
#define CANDY_CRITICAL_SECTION_IMPL_H

CANDY_NAMESPACE_BEGIN

class CriticalSectionImpl
{
public:
	DEFAULT_CONSTRUCTOR_DESTRUCTOR_DELETE_COPY_MOVE(CriticalSectionImpl);

	void startup();
	void cleanup();
	void enter();
	void leave();
private:
	CRITICAL_SECTION m_CriticalSection{};
};

CANDY_NAMESPACE_END

#endif // CANDY_CRITICAL_SECTION_IMPL_H
