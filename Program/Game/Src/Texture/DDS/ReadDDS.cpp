/*****************************************************************//**
 * \file   ReadDDS.cpp
 * \brief  DDSの読み込み
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "ReadDDS.h"

CANDY_NAMESPACE_BEGIN

namespace Texture
{
	namespace DDS
	{
        struct Header
        {
            u32 m_Magic;
            u32 m_Size;
            u32 m_Flags;
            u32 m_Height;
            u32 m_Width;
            u32 m_PitchOrLinearSize;

            u32 m_Depth;
            u32 m_MipMapCount;
            u32 m_Reserved1[11];
            u32 m_PfSize;
            u32 m_PfFlags;
            u32 m_FourCC;

            u32 m_RGBBitCount;
            u32 m_RBitMask;
            u32 m_GBitMask;
            u32 m_BBitMask;
            u32 m_RGBAlphaBitMask;
            u32 m_Caps;
            u32 m_Caps2;
            u32 m_ReservedCaps[2];
            u32 m_Reserved2;
        };
        constexpr u64 HeaderSize = sizeof(Header);
        static_assert(HeaderSize == 128);
	}

    // メモリ確保しつつ読み込み
    std::byte* DDS::ReadAlloc(const std::byte* const _bytes, const u64 _byteSize)
	{
        if (_byteSize < HeaderSize)
        {
            CANDY_LOG("バイトサイズが足りません");
            return nullptr;
        }

        const auto& header = *reinterpret_cast<const Header*>(_bytes);

        if (header.m_Magic != MAKE_FOURCC('D', 'D', 'S', ' '))
        {
            CANDY_LOG("DDSファイルではありません");
            return nullptr;
        }
        if (header.m_Size != 124)
        {
            CANDY_LOG("サイズが124ではありません");
            return nullptr;
        }

        std::byte* result = nullptr;

        switch (header.m_FourCC)
        {
        case MAKE_FOURCC('D', 'X', 'T', '1'):
        {
            const u64 pixelSize = _byteSize - HeaderSize;
            const u64 resultSize = header.m_Width * header.m_Height * 8 / 16;
            result = new std::byte[resultSize];
            memcpy_s(result, resultSize, _bytes + HeaderSize, pixelSize);
            return result;
        }
        break;
        case MAKE_FOURCC('D', 'X', 'T', '5'):
        {
            const u64 pixelSize = _byteSize - HeaderSize;
            const u64 resultSize = header.m_Width * header.m_Height * 16 / 16;
            result = new std::byte[resultSize];
            memcpy_s(result, resultSize, _bytes + HeaderSize, pixelSize);
            return result;
        }
        break;
        case MAKE_FOURCC('D', 'X', '1', '0'):
        {
            CANDY_LOG("dx10拡張は未対応です");
        }
        break;
        default:
        {
            CANDY_LOG("未対応のDDSフォーマットです");
        }
        break;
        }

        return result;
    }
}

CANDY_NAMESPACE_END
