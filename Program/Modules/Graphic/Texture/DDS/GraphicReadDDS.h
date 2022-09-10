/*****************************************************************//**
 * \file   ReadDDS.h
 * \brief  DDSの読み込み
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_TEXTURE_READ_DDS_H
#define CANDY_TEXTURE_READ_DDS_H

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace Texture::DDS
{
	struct ReadTextureInfo
	{
		std::unique_ptr<std::byte[]> m_Buffer;
		u64 m_BufferSize{};
		s32 m_MipMapCount{};
		u32 m_Width{};
		u32 m_Height{};
		graphic::types::GRAPHIC_FORMAT m_Format{};
	};
	// メモリ確保しつつ読み込み
	std::shared_ptr<ReadTextureInfo> ReadAlloc(const std::shared_ptr<std::byte[]>& _bytes, const u64 _byteSize);
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_TEXTURE_READ_DDS_H
