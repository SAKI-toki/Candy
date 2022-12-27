/*****************************************************************//**
 * \file   GraphicReadModel.cpp
 * \brief  モデルの読み込み
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "GraphicReadModel.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

#define GRAPHIC_MODEL_VERSION (0x00000002)

namespace Model
{
    // メモリ確保しつつ読み込み
    std::shared_ptr<ReadModelInfo> ReadAlloc(const std::shared_ptr<std::byte[]>& _bytes, const u64 _byteSize)
    {
        core::Deserializer deserializer;
        if (!deserializer.deserialize(_bytes, _byteSize))return nullptr;

        if (deserializer.getMagic() != CANDY_MAKE_FOURCC_STR("MDL_"))
        {
            CANDY_LOG("モデルファイルではありません");
            return nullptr;
        }
        if (deserializer.getVersion() != GRAPHIC_MODEL_VERSION)
        {
            CANDY_LOG("バージョンが一致しません");
            return nullptr;
        }

        auto result = std::make_shared<ReadModelInfo>();
        const auto meshCount = deserializer.getDataCount(CANDY_MAKE_FOURCC_STR("MESH"));
        const auto materialCount = deserializer.getDataCount(CANDY_MAKE_FOURCC_STR("MAT_"));
        for (s32 i = 0; i < meshCount; ++i)
        {
            const auto data = deserializer.getData(CANDY_MAKE_FOURCC_STR("MESH"), i);
            if (!data)continue;

            u32 offset = 0;

            ReadMeshInfo meshInfo;
            meshInfo.m_Header = *reinterpret_cast<const ReadMeshHeader*>(data.get() + offset);
            offset += sizeof(ReadMeshHeader);

            meshInfo.m_ReadVertexInfoList.resize(meshInfo.m_Header.m_ReadVertexInfoCount);
            const u32 vertexInfoByteSize = sizeof(ReadVertexInfo) * meshInfo.m_Header.m_ReadVertexInfoCount;
            memcpy(meshInfo.m_ReadVertexInfoList.data(), data.get() + offset, vertexInfoByteSize);
            offset += vertexInfoByteSize;

            meshInfo.m_VertexIndexList.resize(meshInfo.m_Header.m_VertexIndexCount);
            const u32 vertexIndexByteSize = sizeof(u32) * meshInfo.m_Header.m_VertexIndexCount;
            memcpy(meshInfo.m_VertexIndexList.data(), data.get() + offset, vertexIndexByteSize);
            offset += vertexIndexByteSize;

            result->m_ReadMeshInfoList.push_back(meshInfo);
        }
        for (s32 i = 0; i < materialCount; ++i)
        {
            const auto data = deserializer.getData(CANDY_MAKE_FOURCC_STR("MAT_"), i);
            if (!data)continue;

            u32 offset = 0;

            ReadMaterialInfo materialInfo;
            materialInfo.m_Header = *reinterpret_cast<const ReadMaterialHeader*>(data.get() + offset);
            offset += sizeof(ReadMaterialHeader);

            materialInfo.m_TextureInfoList.resize(materialInfo.m_Header.m_TextureCount);
            const u32 textureByteSize = sizeof(ReadTextureInfo) * materialInfo.m_Header.m_TextureCount;
            memcpy(materialInfo.m_TextureInfoList.data(), data.get() + offset, textureByteSize);
            offset += textureByteSize;

            result->m_ReadMaterialInfoList.push_back(materialInfo);
        }

        return result;
    }

}

CANDY_GRAPHIC_NAMESPACE_END
