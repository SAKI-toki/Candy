/*****************************************************************//**
 * \file   StaticVector.inl
 * \brief  固定長配列vector
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_CORE_STATIC_VECTOR_INL
#define CANDY_CORE_STATIC_VECTOR_INL

#include "StaticVector.h"

CANDY_CORE_NAMESPACE_BEGIN

template<typename T,s32 Size>
StaticVector<T, Size>::iterator StaticVector<T, Size>::begin()noexcept
{
	return m_Arr;
}
template<typename T, s32 Size>
StaticVector<T, Size>::iterator StaticVector<T, Size>::end()noexcept
{
	return m_EndIterator;
}
template<typename T, s32 Size>
StaticVector<T, Size>::const_iterator StaticVector<T, Size>::cbegin()const noexcept
{
	return m_Arr;
}
template<typename T, s32 Size>
StaticVector<T, Size>::const_iterator StaticVector<T, Size>::cend()const noexcept
{
	return m_EndIterator;
}
template<typename T, s32 Size>
StaticVector<T, Size>::reverse_iterator StaticVector<T, Size>::rbegin()noexcept
{
	return m_EndIterator - 1;
}
template<typename T, s32 Size>
StaticVector<T, Size>::reverse_iterator StaticVector<T, Size>::rend()noexcept
{
	return m_Arr - 1;
}
template<typename T, s32 Size>
StaticVector<T, Size>::const_reverse_iterator StaticVector<T, Size>::crbegin()const noexcept
{
	return m_EndIterator - 1;
}
template<typename T, s32 Size>
StaticVector<T, Size>::const_reverse_iterator StaticVector<T, Size>::crend()const noexcept
{
	return m_Arr - 1;
}

template<typename T, s32 Size>
StaticVector<T, Size>::size_type StaticVector<T, Size>::size()const noexcept
{
	return m_EndIterator - m_Arr;
}
template<typename T, s32 Size>
s32 StaticVector<T, Size>::sizeS32()const noexcept
{
	return static_cast<s32>(m_EndIterator - m_Arr);
}
template<typename T, s32 Size>
StaticVector<T, Size>::size_type StaticVector<T, Size>::max_size()const noexcept
{
	return Size;
}
template<typename T, s32 Size>
StaticVector<T, Size>::size_type StaticVector<T, Size>::capacity()const noexcept
{
	return Size;
}
template<typename T, s32 Size>
bool StaticVector<T, Size>::empty()const noexcept
{
	return m_EndIterator == m_Arr;
}

template<typename T, s32 Size>
StaticVector<T, Size>::reference StaticVector<T, Size>::operator[](const size_type _idx)
{
	return m_Arr[_idx];
}
template<typename T, s32 Size>
StaticVector<T, Size>::const_reference StaticVector<T, Size>::operator[](const size_type _idx)const
{
	return m_Arr[_idx];
}
template<typename T, s32 Size>
StaticVector<T, Size>::pointer StaticVector<T, Size>::data()noexcept
{
	return m_Arr;
}
template<typename T, s32 Size>
StaticVector<T, Size>::const_pointer StaticVector<T, Size>::data()const noexcept
{
	return m_Arr;
}
template<typename T, s32 Size>
StaticVector<T, Size>::reference StaticVector<T, Size>::front()
{
	return m_Arr;
}
template<typename T, s32 Size>
StaticVector<T, Size>::const_reference StaticVector<T, Size>::front()const
{
	return m_Arr;
}
template<typename T, s32 Size>
StaticVector<T, Size>::reference StaticVector<T, Size>::back()
{
	return m_EndIterator - 1;
}
template<typename T, s32 Size>
StaticVector<T, Size>::const_reference StaticVector<T, Size>::back()const
{
	return m_EndIterator - 1;
}

template<typename T, s32 Size>
bool StaticVector<T, Size>::push_back(const_reference _value)
{
	if (size() >= Size)return false;
	*m_EndIterator = _value;
	++m_EndIterator;
	return true;
}
template<typename T, s32 Size>
bool StaticVector<T, Size>::push_back(rvalue_reference _value)
{
	if (size() >= Size)return false;
	*m_EndIterator = std::move(_value);
	++m_EndIterator;
	return true;
}

template<typename T, s32 Size>
StaticVector<T, Size>::iterator StaticVector<T, Size>::erase(iterator _itr)
{
	auto return_itr = _itr;
	std::destroy_at(_itr);
	for (auto moveItr = _itr; moveItr != end() - 1; ++moveItr)
	{
		*moveItr = *(moveItr + 1);
	}
	--m_EndIterator;
	return return_itr;
}
template<typename T, s32 Size>
StaticVector<T, Size>::iterator StaticVector<T, Size>::erase(iterator _first, iterator _last)
{
	auto return_itr = _first;
	for (auto eraseItr = _first; eraseItr != _last; ++eraseItr)
	{
		std::destroy_at(eraseItr);
	}

	for (; _last != end(); ++_first, ++_last)
	{
		*_first = *_last;
	}
	m_EndIterator -= _last - _first;
	return return_itr;
}

template<typename T, s32 Size>
void StaticVector<T, Size>::pop_back()
{
	if (empty())return;
	erase(end() - 1);
}

template<typename T, s32 Size>
void StaticVector<T, Size>::clear()
{
	erase(begin(), end());
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_STATIC_VECTOR_INL
