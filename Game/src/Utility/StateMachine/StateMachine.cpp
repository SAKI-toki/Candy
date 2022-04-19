#include "StateMachine.h"

CANDY_NAMESPACE_BEGIN

namespace StateMachine
{
	void Manager::startup(StatePtrType&& _startState)
	{
		switchStateImpl(std::move(_startState));
	}

	void Manager::cleanup()
	{
		if (m_State)m_State->cleanup();
		m_State.release();
	}

	void Manager::update()
	{
		if (m_State)
		{
			m_State->update();
			if (m_State->isEnd())
			{
				switchStateImpl(m_State->getNextState());
			}
		}
	}

	void Manager::switchStateImpl(StatePtrType&& _nextState)
	{
		if (m_State)m_State->cleanup();
		m_State = std::move(_nextState);
		if (m_State)m_State->startup();
	}
}

CANDY_NAMESPACE_END
