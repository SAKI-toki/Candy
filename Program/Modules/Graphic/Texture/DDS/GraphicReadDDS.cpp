/*****************************************************************//**
 * \file   GraphicReadDDS.cpp
 * \brief  DDSの読み込み
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "GraphicReadDDS.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

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

        void ReadBcFormatImpl(std::shared_ptr<DDS::ReadTextureInfo>& _readTextureInfo, const std::shared_ptr<std::byte[]>& _bytes, const Header& _header);
	}

    // メモリ確保しつつ読み込み
    std::shared_ptr<DDS::ReadTextureInfo> DDS::ReadAlloc(const std::shared_ptr<std::byte[]>& _bytes, const u64 _byteSize)
	{
        if (!_bytes)
        {
            return nullptr;
        }
        if (_byteSize < HeaderSize)
        {
            CANDY_LOG("バイトサイズが足りません");
            return nullptr;
        }

        const auto& header = *reinterpret_cast<const Header*>(_bytes.get());

        if (header.m_Magic != CANDY_MAKE_FOURCC('D', 'D', 'S', ' '))
        {
            CANDY_LOG("DDSファイルではありません");
            return nullptr;
        }
        if (header.m_Size != 124)
        {
            CANDY_LOG("サイズが124ではありません");
            return nullptr;
        }

        auto result = std::make_shared<ReadTextureInfo>();
        result->m_Width = header.m_Width;
        result->m_Height = header.m_Height;
        result->m_MipMapCount = header.m_MipMapCount;

        switch (header.m_FourCC)
        {
        case CANDY_MAKE_FOURCC('D', 'X', 'T', '1'):
        {
            result->m_Format = graphic::types::GRAPHIC_FORMAT::BC1_UNORM;
            ReadBcFormatImpl(result, _bytes, header);
            return result;
        }
        break;
        case CANDY_MAKE_FOURCC('D', 'X', 'T', '5'):
        {
            result->m_Format = graphic::types::GRAPHIC_FORMAT::BC3_UNORM;
            ReadBcFormatImpl(result, _bytes, header);
            return result;
        }
        break;
        case CANDY_MAKE_FOURCC('D', 'X', '1', '0'):
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

        return nullptr;
    }

    void DDS::ReadBcFormatImpl(std::shared_ptr<DDS::ReadTextureInfo>& _readTextureInfo, const std::shared_ptr<std::byte[]>& _bytes, const Header& _header)
    {
        const u64 bpp = graphic::types::GetBppGraphicFormat(_readTextureInfo->m_Format);

        u64 resultSize = 0;

        for (u32 i = 1; i <= _header.m_MipMapCount; ++i)
        {
            u64 rate = (u64)std::pow(2, i - 1);
            const u64 width = core::Max(_header.m_Width / rate, 4);
            const u64 height = core::Max(_header.m_Height / rate, 4);
            const u64 size = width * height * bpp / 8;
            const u64 rowPitch = width * 4 * bpp / 8;
            if (rowPitch > 256)
            {
                resultSize += size;
            }
            else
            {
                resultSize += core::AlignAdjust(height / 4 * 256, 512);
            }
        }
        _readTextureInfo->m_Buffer = std::make_unique<std::byte[]>(resultSize);
        _readTextureInfo->m_BufferSize = resultSize;
        resultSize = 0;

        std::byte* p = _bytes.get() + HeaderSize;
        for (u32 i = 1; i <= _header.m_MipMapCount; ++i)
        {
            u64 rate = (u64)std::pow(2, i - 1);
            const u64 width = core::Max(_header.m_Width / rate, 4);
            const u64 height = core::Max(_header.m_Height / rate, 4);
            const u64 size = width * height * bpp / 8;
            const u64 rowPitch = width * 4 * bpp / 8;
            if (rowPitch > 256)
            {
                memcpy_s(
                    _readTextureInfo->m_Buffer.get() + resultSize, 
                    size, 
                    p, 
                    size);
                resultSize += size;
            }
            else
            {
                for (s32 j = 0; j < height / 4; ++j)
                {
                    memcpy_s(
                        _readTextureInfo->m_Buffer.get() + resultSize + 256 * j,
                        rowPitch,
                        p + rowPitch * j,
                        rowPitch);
                }
                resultSize += core::AlignAdjust(height / 4 * 256, 512);
            }
            p += size;
        }
    }
}

CANDY_GRAPHIC_NAMESPACE_END
