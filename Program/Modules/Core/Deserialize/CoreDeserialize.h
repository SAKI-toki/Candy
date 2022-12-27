/*****************************************************************//**
 * \file   CoreDeserialize.h
 * \brief  デシリアライズ
 * \author Yu Ishiyama.
 * \date   2022/06/02
 *********************************************************************/

#ifndef CANDY_CORE_FILE_READ_CHUNK_H
#define CANDY_CORE_FILE_READ_CHUNK_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

class Deserializer
{
public:
	bool deserialize(const std::shared_ptr<std::byte[]>& _bytes, const u64 _byteSize);
	std::shared_ptr<std::byte[]> getData(const u32 _id, const s32 _index = 0) const;
	s32 getDataCount(const u32 _id) const;
	u32 getMagic()const { return m_Magic; }
	u32 getVersion()const { return m_Version; }

private:
	u32 m_Magic{};
	u32 m_Version{};

	std::map<u32, std::vector<std::shared_ptr<std::byte[]>>> m_DataMap;
};

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_FILE_READ_CHUNK_H
