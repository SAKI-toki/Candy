#include "Hash.h"

CANDY_NAMESPACE_BEGIN

namespace Fnv
{
	namespace Impl
	{
		inline constexpr u32 Prime32 = 16777619;
		inline constexpr u32 OffsetBasic32 = 2166136261;

		template<typename T>
		u32 Hash32Impl(const T* const _bytes, const s32 _length)
		{
			u32 hash = OffsetBasic32;
			for (s32 i = 0; i < _length; ++i)
			{
				hash *= Prime32;
				hash ^= _bytes[i];
			}
			return hash;
		}

		template<typename T, s32 N>
		constexpr u32 StaticHash32Impl(const T(&_bytes)[N])
		{
			u32 hash = OffsetBasic32;
			for (s32 i = 0; i < N - 1; ++i)
			{
				hash *= Prime32;
				hash ^= _bytes[i];
			}
			return hash;
		}
	}
}

inline u32 Fnv::Hash32(const char* const _str, const s32 _length)
{
	if (_length <= 0)
	{
		CANDY_LOG("サイズ0の文字列のハッシュ値を取得しようとした");
		return 0;
	}
	return Impl::Hash32Impl(_str, _length);
}

inline u32 Fnv::Hash32(const char* const _str)
{
	return Hash32(_str, static_cast<s32>(strlen(_str)));
}

template<s32 N>
constexpr u32 Fnv::Impl::StaticHash32(const char(&_str)[N])
{
	return Impl::StaticHash32Impl(_str);
}

CANDY_NAMESPACE_END
