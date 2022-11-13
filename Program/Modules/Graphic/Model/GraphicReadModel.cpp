/*****************************************************************//**
 * \file   GraphicReadModel.cpp
 * \brief  モデルの読み込み
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "GraphicReadModel.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

#define GRAPHIC_MODEL_VERSION (0x00000101)

namespace Model
{
    struct FileHeader
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

    // メモリ確保しつつ読み込み
    std::shared_ptr<ReadModelInfo> ReadAlloc(const std::shared_ptr<std::byte[]>& _bytes, const u64 _byteSize)
    {
        if (!_bytes)
        {
            return nullptr;
        }
        if (_byteSize < sizeof(FileHeader))
        {
            CANDY_LOG("バイトサイズが足りません");
            return nullptr;
        }

        u32 offset = 0;
        const auto& header = *reinterpret_cast<const FileHeader*>(_bytes.get() + offset);
        offset += sizeof(FileHeader);

        if (header.m_Magic != CANDY_MAKE_FOURCC_STR("FBX_"))
        {
            CANDY_LOG("FBXファイルではありません");
            return nullptr;
        }
        if (header.m_HeaderSize != sizeof(FileHeader))
        {
            CANDY_LOG("サイズが一致しません");
            return nullptr;
        }
        if (header.m_Version != GRAPHIC_MODEL_VERSION)
        {
            CANDY_LOG("バージョンが一致しません");
            return nullptr;
        }

        auto result = std::make_shared<ReadModelInfo>();

        while (offset + sizeof(Chunk) <= header.m_Size)
        {
            const Chunk& chunk = *reinterpret_cast<Chunk*>(_bytes.get() + offset);
            offset += sizeof(Chunk);
            switch (chunk.m_Id)
            {
            case CANDY_MAKE_FOURCC_STR("MESH"):
            {
                ReadMeshInfo meshInfo;
                meshInfo.m_Header = *reinterpret_cast<const ReadMeshHeader*>(_bytes.get() + offset);
                offset += sizeof(ReadMeshHeader);

                meshInfo.m_ControlPointList.resize(meshInfo.m_Header.m_ControlPointCount);
                const u32 controlPointByteSize = sizeof(Vec4) * meshInfo.m_Header.m_ControlPointCount;
                memcpy(meshInfo.m_ControlPointList.data(), reinterpret_cast<Vec4*>(_bytes.get() + offset), controlPointByteSize);
                offset += controlPointByteSize;

                meshInfo.m_ReadVertexInfoList.resize(meshInfo.m_Header.m_VertexCount);
                const u32 vertexByteSize = sizeof(ReadVertexInfo) * meshInfo.m_Header.m_VertexCount;
                memcpy(meshInfo.m_ReadVertexInfoList.data(), reinterpret_cast<ReadVertexInfo*>(_bytes.get() + offset), vertexByteSize);
                offset += vertexByteSize;

                meshInfo.m_ControlPointIndexList.resize(meshInfo.m_Header.m_VertexCount);
                const u32 controlPointIndexByteSize = sizeof(u32) * meshInfo.m_Header.m_VertexCount;
                memcpy(meshInfo.m_ControlPointIndexList.data(), reinterpret_cast<u32*>(_bytes.get() + offset), controlPointIndexByteSize);
                offset += controlPointIndexByteSize;

                result->m_ReadMeshInfoList.push_back(meshInfo);
            }
            break;
            case CANDY_MAKE_FOURCC_STR("MAT_"):
            {
                ReadMaterialInfo materialInfo;
                materialInfo.m_Header = *reinterpret_cast<const ReadMaterialHeader*>(_bytes.get() + offset);
                offset += sizeof(ReadMaterialHeader);

                materialInfo.m_TextureInfoList.resize(materialInfo.m_Header.m_TextureCount);
                const u32 textureByteSize = sizeof(ReadTextureInfo) * materialInfo.m_Header.m_TextureCount;
                memcpy(materialInfo.m_TextureInfoList.data(), reinterpret_cast<ReadTextureInfo*>(_bytes.get() + offset), textureByteSize);
                offset += textureByteSize;

                result->m_ReadMaterialInfoList.push_back(materialInfo);
            }
            break;
            default:
            {
                CANDY_ASSERT(false);
            }
            break;
            }
        }

        return result;
    }

}

CANDY_GRAPHIC_NAMESPACE_END
