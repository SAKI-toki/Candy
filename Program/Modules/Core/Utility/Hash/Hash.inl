/*****************************************************************//**
 * \file   Hash.inl
 * \brief  ハッシュ
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_HASH_INL
#define CANDY_CORE_HASH_INL

#include "Hash.h"
#include <Core/Utility/StringSystem/UpperLower/StringSystemToUpperLower.h>

CANDY_CORE_NAMESPACE_BEGIN

namespace Fnv
{
	namespace Impl
	{
		inline constexpr u32 Prime32 = 16777619;
		inline constexpr u32 OffsetBasic32 = 2166136261;

		// ハッシュ計算の実装部
		template<typename T, typename Projection = std::identity>
		constexpr u32 Hash32CalcImpl(const T* const _bytes, const s32 _length, Projection _proj = {})
		{
			u32 hash = OffsetBasic32;
			for (s32 i = 0; i < _length; ++i)
			{
				hash *= Prime32;
				hash ^= _proj(_bytes[i]);
			}
			return hash;
		}

		// ハッシュ計算の実装部
		template<typename T>
		constexpr u32 Hash32Impl(const T* const _bytes, const s32 _length)
		{
			return Hash32CalcImpl(_bytes, _length);
		}

		// ハッシュ計算の実装部
		template<typename T>
		constexpr u32 Hash32LowImpl(const T* const _bytes, const s32 _length)
		{
			return Hash32CalcImpl(_bytes, _length, StringSystem::ToLower);
		}
	}
}

// ハッシュ計算
inline u32 Fnv::Hash32(const char* const _str, const s32 _length)
{
	if (_length <= 0)
	{
		return 0;
	}
	return Impl::Hash32Impl(_str, _length);
}
inline u32 Fnv::Hash32(const char* const _str)
{
	return Hash32(_str, static_cast<s32>(strlen(_str)));
}
inline u32 Fnv::Hash32(const std::string_view _str)
{
	return Hash32(_str.data(), static_cast<s32>(_str.size()));
}

// ハッシュ計算(小文字)
inline u32 Fnv::Hash32Low(const char* const _str, const s32 _length)
{
	if (_length <= 0)
	{
		return 0;
	}
	return Impl::Hash32LowImpl(_str, _length);
}
inline u32 Fnv::Hash32Low(const char* const _str)
{
	return Hash32Low(_str, static_cast<s32>(strlen(_str)));
}
inline u32 Fnv::Hash32Low(const std::string_view _str)
{
	return Hash32Low(_str.data(), static_cast<s32>(_str.size()));
}

// ハッシュ計算(コンパイル時)
template<s32 N>
constexpr u32 Fnv::Impl::StaticHash32(const char(&_str)[N])
{
	return Impl::Hash32Impl(_str, N - 1);
}
template<s32 N>
constexpr u32 Fnv::Impl::StaticHash32Low(const char(&_str)[N])
{
	return Impl::Hash32LowImpl(_str, N - 1);
}

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_HASH_INL
