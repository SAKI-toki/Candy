#ifndef CANDY_STATIC_VECTOR_H
#define CANDY_STATIC_VECTOR_H

CANDY_NAMESPACE_BEGIN

template<typename T, s32 Size>
class StaticVector
{
public:
	using reference = T&;
	using rvalue_reference = T&&;
	using const_reference = const T&;
	using iterator = T*;
	using const_iterator = const T*;
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using reverse_iterator = T*;
	using const_reverse_iterator = const T*;
	using value_type = T;
	using iterator_type = T*;
	using pointer_type = T*;
	using size_type = u64;

	iterator begin()noexcept;
	iterator end()noexcept;
	const_iterator cbegin()const noexcept;
	const_iterator cend()const noexcept;
	reverse_iterator rbegin()noexcept;
	reverse_iterator rend()noexcept;
	const_reverse_iterator crbegin()const noexcept;
	const_reverse_iterator crend()const noexcept;

	size_type size()const noexcept;
	s32 sizeS32()const noexcept;
	size_type max_size()const noexcept;
	size_type capacity()const noexcept;
	bool empty()const noexcept;

	reference operator[](const size_type);
	const_reference operator[](const size_type)const;
	pointer data()noexcept;
	const_pointer data()const noexcept;
	reference front();
	const_reference front()const;
	reference back();
	const_reference back()const;

	bool push_back(const_reference);
	bool push_back(rvalue_reference);

	iterator erase(iterator);
	iterator erase(iterator, iterator);

	void pop_back();

	void clear();

private:
	T m_Arr[Size]{};
	T* m_EndIterator = m_Arr;
};

CANDY_NAMESPACE_END

#include "StaticVector.inl"

#endif // CANDY_STATIC_VECTOR_H
