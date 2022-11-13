/*****************************************************************//**
 * \file   GraphicReadModel.h
 * \brief  DDSの読み込み
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_GRAPHIC_READ_MODEL_H
#define CANDY_GRAPHIC_READ_MODEL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace Model
{
	struct ReadVertexInfo
	{
		Vec4 m_Normal;
		Vec4 m_TexCoord0;
		Vec4 m_TexCoord1;
	};

	struct ReadMeshHeader
	{
		u32 m_ControlPointCount{};
		u32 m_VertexCount{};
		char m_Name[128]{ "" };
		char m_MaterialName[128]{ "" };
	};
	struct ReadMeshInfo
	{
		ReadMeshHeader m_Header;
		std::vector<Vec4> m_ControlPointList;
		std::vector<ReadVertexInfo> m_ReadVertexInfoList;
		std::vector<u32> m_ControlPointIndexList;
	};
	struct ReadMaterialHeader
	{
		u32 m_TextureCount{};
		char m_Name[128]{ "" };
	};
	struct ReadTextureInfo
	{
		char m_FilePath[256]{ "" };
	};
	struct ReadMaterialInfo
	{
		ReadMaterialHeader m_Header;
		std::vector<ReadTextureInfo> m_TextureInfoList;
	};

	struct ReadModelInfo
	{
		std::vector<ReadMeshInfo> m_ReadMeshInfoList;
		std::vector<ReadMaterialInfo> m_ReadMaterialInfoList;
	};

	// メモリ確保しつつ読み込み
	std::shared_ptr<ReadModelInfo> ReadAlloc(const std::shared_ptr<std::byte[]>& _bytes, const u64 _byteSize);
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_READ_MODEL_H
