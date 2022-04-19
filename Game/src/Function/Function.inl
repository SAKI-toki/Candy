#include "Function.h"

CANDY_NAMESPACE_BEGIN

template<typename RetType, typename ...ArgTypes>
Function<RetType(ArgTypes...)>::Function(const Function& _other)
{
	if (_other.m_pHolder)
	{
		_other.m_pHolder->copy(m_pHolder);
	}
}
template<typename RetType, typename ...ArgTypes>
Function<RetType(ArgTypes...)>& Function<RetType(ArgTypes...)>::operator=(const Function& _other)
{
	if (this != &_other)
	{
		if (_other.m_pHolder)
		{
			_other.m_pHolder->copy(m_pHolder);
		}
	}
	return *this;
}
template<typename RetType, typename ...ArgTypes>
Function<RetType(ArgTypes...)>::Function(Function&& _other)
{
	m_pHolder = std::exchange(_other.m_pHolder, nullptr);
}
template<typename RetType, typename ...ArgTypes>
Function<RetType(ArgTypes...)>& Function<RetType(ArgTypes...)>::operator=(Function&& _other)
{
	if (this != &_other)
	{
		m_pHolder = std::exchange(_other.m_pHolder, nullptr);
	}
	return *this;
}

template<typename RetType, typename ...ArgTypes>
template<typename F>
Function<RetType(ArgTypes...)>::Function(F _f)
{
	createHolder<F>(_f);
}

template<typename RetType, typename ...ArgTypes>
template<typename F>
Function<RetType(ArgTypes...)>& Function<RetType(ArgTypes...)>::operator=(F _f)
{
	createHolder<F>(_f);
	return *this;
}

template<typename RetType, typename ...ArgTypes>
RetType Function<RetType(ArgTypes...)>::operator()(ArgTypes... _args)
{
	if (m_pHolder)
	{
		m_pHolder->invoke(std::forward<ArgTypes>(_args)...);
	}
}

template<typename RetType, typename ...ArgTypes>
template<typename F>
void Function<RetType(ArgTypes...)>::createHolder(F _f)
{
	m_pHolder = std::make_unique<HolderBase>(new Holder<F>(_f));
}

CANDY_NAMESPACE_END
