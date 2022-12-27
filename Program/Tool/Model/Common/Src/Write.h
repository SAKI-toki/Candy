#pragma once
#include "DataFormat.h"

void ConvertWrite(const std::string& _outPath, const WriteData& _writeData);
void WriteChunk(std::ostringstream& _os, const std::string& _str, const u32 _chunkId);

namespace Material
{
	std::string Write(const MaterialInfo& _materialInfo);
}

namespace Mesh
{
	std::string Write(const MeshInfo& _meshInfo);
}
