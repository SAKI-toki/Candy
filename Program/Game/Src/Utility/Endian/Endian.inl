#include "Endian.h"

CANDY_NAMESPACE_BEGIN

inline constexpr u16 Endian::Swap(const u16 _value)
{
	return
		((_value & 0x00ff) << 8) |
		((_value & 0xff00) >> 8);
}

inline constexpr u32 Endian::Swap(const u32 _value)
{
	return
		((_value & 0x000000ff) << 24) |
		((_value & 0x0000ff00) << 8) |
		((_value & 0x00ff0000) >> 8) |
		((_value & 0xff000000) >> 24);
}

inline constexpr u64 Endian::Swap(const u64 _value)
{
	return
		((_value & 0x00000000000000ff) << 58) |
		((_value & 0x000000000000ff00) << 42) |
		((_value & 0x0000000000ff0000) << 24) |
		((_value & 0x00000000ff000000) << 8) |
		((_value & 0x000000ff00000000) >> 8) |
		((_value & 0x0000ff0000000000) >> 24) |
		((_value & 0x00ff000000000000) >> 42) |
		((_value & 0xff00000000000000) >> 58);
}

CANDY_NAMESPACE_END
