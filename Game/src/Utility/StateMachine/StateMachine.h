#ifndef CANDY_STATE_MACHINE_H
#define CANDY_STATE_MACHINE_H

CANDY_NAMESPACE_BEGIN

namespace StateMachine
{
	class StateBase;
	using StatePtrType = std::unique_ptr<StateBase>;

	class StateBase
	{
	public:
		virtual ~StateBase() = default;

		virtual void startup() = 0;
		virtual void cleanup() = 0;
		virtual void update() = 0;
		virtual bool isEnd()const = 0;
		virtual StatePtrType getNextState() = 0;
	};

	class Manager
	{
	public:
		void startup(StatePtrType&& _startState);
		void cleanup();
		void update();

	private:
		void switchStateImpl(StatePtrType&& _nextState);

		StatePtrType m_State;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_STATE_MACHINE_H
