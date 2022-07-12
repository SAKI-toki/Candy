/*****************************************************************//**
 * \file   CriticalSectionImpl.h
 * \brief  クリティカルセクションの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CORE_CRITICAL_SECTION_IMPL_H
#define CANDY_CORE_CRITICAL_SECTION_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

class CriticalSectionImpl
{
protected:
	CANDY_DEFAULT_CONSTRUCTOR_DESTRUCTOR(CriticalSectionImpl);
	CANDY_DELETE_COPY_MOVE(CriticalSectionImpl);

	// 初期化
	void startup();
	// 破棄
	void cleanup();
	// 開始
	void enter();
	// 終了
	void leave();
private:
	CRITICAL_SECTION m_CriticalSection{};
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_CRITICAL_SECTION_IMPL_H
