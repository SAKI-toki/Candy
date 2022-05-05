#ifndef CANDY_HASH_H
#define CANDY_HASH_H

CANDY_NAMESPACE_BEGIN

namespace Fnv
{
	u32 Hash32(const char* const _str, const s32 _length);
	u32 Hash32(const char* const _str);
	u32 Hash32(const std::string& _str);

	u32 Hash32Low(const char* const _str, const s32 _length);
	u32 Hash32Low(const char* const _str);
	u32 Hash32Low(const std::string& _str);

	namespace Impl
	{
		template<s32 N>
		constexpr u32 StaticHash32(const char(&_str)[N]);
		template<s32 N>
		constexpr u32 StaticHash32Low(const char(&_str)[N]);
	}

#define CANDY_STATIC_FNV_HASH32(STR) (std::integral_constant<u32, Fnv::Impl::StaticHash32(STR)>::value)
#define CANDY_STATIC_FNV_HASH32_LOW(STR) (std::integral_constant<u32, Fnv::Impl::StaticHash32Low(STR)>::value)
}

CANDY_NAMESPACE_END

#include "Hash.inl"

#endif // CANDY_HASH_H
