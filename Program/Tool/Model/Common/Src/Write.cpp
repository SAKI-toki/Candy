#include "Write.h"

void ConvertWrite(const std::string& _outPath, const WriteData& _writeData)
{
	std::ostringstream os;

	for (const auto& meshInfo : _writeData.m_MeshInfoList)
	{
		WriteChunk(os, Write(meshInfo), CANDY_MAKE_FOURCC_STR("MESH"));
	}

	for (const auto& materialInfo : _writeData.m_MaterialInfoList)
	{
		WriteChunk(os, Write(materialInfo), CANDY_MAKE_FOURCC_STR("MAT_"));
	}

	std::ofstream ofs(_outPath, std::ios::binary);

	FileHeader fileHeader;

	fileHeader.m_Magic = CANDY_MAKE_FOURCC_STR("MDL_");
	fileHeader.m_Version = CONVERT_VERSION;
	fileHeader.m_HeaderSize = sizeof(FileHeader);
	fileHeader.m_Size = sizeof(FileHeader) + (u32)os.str().size();

	ofs.write((const c8*)&fileHeader, sizeof(FileHeader));
	ofs.write((const c8*)os.str().data(), os.str().size());

	ofs.close();

}

void WriteChunk(std::ostringstream& _os, const std::string& _str, const u32 _chunkId)
{
	Chunk  chunk;
	chunk.m_Id = _chunkId;
	chunk.m_Size = (u32)_str.size();
	_os.write((const c8*)&chunk, sizeof(Chunk));
	_os.write((const c8*)_str.data(), _str.size());
}

std::string Material::Write(const MaterialInfo& _materialInfo)
{
	std::ostringstream os;
	os.write((const c8*)&_materialInfo.m_Header, sizeof(MaterialHeader));
	os.write((const c8*)_materialInfo.m_TextureInfoList.data(), sizeof(TextureInfo) * _materialInfo.m_Header.m_TextureCount);
	return os.str();
}

std::string Mesh::Write(const MeshInfo& _meshInfo)
{
	std::ostringstream os;

	os.write((const c8*)&_meshInfo.m_Header, sizeof(MeshHeader));
	os.write((const c8*)_meshInfo.m_VertexInfoList.data(), sizeof(VertexInfo) * _meshInfo.m_Header.m_VertexInfoCount);
	os.write((const c8*)_meshInfo.m_VertexIndexList.data(), sizeof(u32) * _meshInfo.m_Header.m_VertexIndexCount);

	return os.str();
}
