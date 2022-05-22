#ifndef CANDY_ENDIAN_H
#define CANDY_ENDIAN_H

CANDY_NAMESPACE_BEGIN

namespace Endian
{
	constexpr u16 Swap(const u16 _value);
	constexpr u32 Swap(const u32 _value);
	constexpr u64 Swap(const u64 _value);
}

CANDY_NAMESPACE_END

#include "Endian.inl"

#endif // CANDY_ENDIAN_H
