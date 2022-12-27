/*****************************************************************//**
 * \file   CoreDeserialize.cpp
 * \brief  デシリアライズ
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#include "CoreDeserialize.h"

CANDY_CORE_NAMESPACE_BEGIN

namespace DeserializeImpl
{
	struct Header
	{
		u32 m_Magic;
		u32 m_Version;
		u32 m_HeaderSize;
		u32 m_Size;
	};
	struct Chunk
	{
		union
		{
			u32 m_Id;
			struct
			{
				char m_Ids[4];
			};
		};
		u32 m_Size;
	};
}

bool Deserializer::deserialize(const std::shared_ptr<std::byte[]>& _bytes, const u64 _byteSize)
{
	if (!_bytes)
	{
		return false;
	}
	if (_byteSize < sizeof(DeserializeImpl::Header))
	{
		CANDY_LOG("バイトサイズが足りません");
		return false;
	}

	u32 offset = 0;
	const auto& header = *reinterpret_cast<DeserializeImpl::Header*>(_bytes.get() + offset);
	offset += sizeof(DeserializeImpl::Header);

	if (header.m_HeaderSize != sizeof(DeserializeImpl::Header))
	{
		CANDY_LOG("サイズが一致しません");
		return false;
	}
	m_Magic = header.m_Magic;
	m_Version = header.m_Version;

	while (offset + sizeof(DeserializeImpl::Chunk) <= header.m_Size)
	{
		const DeserializeImpl::Chunk& chunk = *reinterpret_cast<DeserializeImpl::Chunk*>(_bytes.get() + offset);
		offset += sizeof(DeserializeImpl::Chunk);
		auto data = std::make_shared<std::byte[]>(chunk.m_Size);
		if (!data)
		{
			CANDY_LOG("チャンク読み込み中にメモリが不足しました");
			return false;
		}
		std::memcpy(data.get(), _bytes.get() + offset, chunk.m_Size);
		offset += chunk.m_Size;
		m_DataMap[chunk.m_Id].push_back(data);
	}
	return true;
}

std::shared_ptr<std::byte[]> Deserializer::getData(const u32 _id, const s32 _index) const
{
	const auto itr = m_DataMap.find(_id);
	if (itr == m_DataMap.end())return nullptr;
	if (_index < 0)return nullptr;
	if (_index >= static_cast<s32>(itr->second.size()))return nullptr;
	return itr->second[_index];
}

s32 Deserializer::getDataCount(const u32 _id) const
{
	const auto itr = m_DataMap.find(_id);
	if (itr == m_DataMap.end())return 0;
	return static_cast<s32>(itr->second.size());
}

CANDY_CORE_NAMESPACE_END
