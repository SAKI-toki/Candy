#include "InputMouse.h"

CANDY_NAMESPACE_BEGIN

namespace Input
{
	void Mouse::startup()
	{
		reset();
	}

	void Mouse::cleanup()
	{

	}

	void Mouse::update()
	{
		m_PrevScreenPos = m_ScreenPos;
		m_PrevClientPos = m_ClientPos;

		m_ScreenPos = MouseImpl::getScreenPos();
		m_ClientPos = MouseImpl::toClientPos(m_ScreenPos);
	}

	void Mouse::reset()
	{
		m_ScreenPos = ZeroVector;
		m_ClientPos = ZeroVector;
		m_PrevScreenPos = ZeroVector;
		m_PrevClientPos = ZeroVector;
	}

	Vec4 Mouse::getScreenPos()const		{ return m_ScreenPos; }
	Vec4 Mouse::getClientPos()const		{ return m_ClientPos; }
	Vec4 Mouse::getPrevScreenPos()const { return m_PrevScreenPos; }
	Vec4 Mouse::getPrevClientPos()const { return m_PrevClientPos; }
}

CANDY_NAMESPACE_END
