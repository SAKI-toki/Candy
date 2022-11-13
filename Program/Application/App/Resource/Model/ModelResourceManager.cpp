/*****************************************************************//**
 * \file   ModelResourceManager.cpp
 * \brief  モデルリソースの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "ModelResourceManager.h"
#include <App/Defines/ModelDefine.h>

CANDY_APP_NAMESPACE_BEGIN

namespace ModelResourceManager
{
	std::map<u32, ModelInfo> m_ModelInfoMap;
	ModelInfo m_DummyModelInfo;
}

void ModelResourceManager::Startup()
{
	auto& graphicDevice = graphic::System::GetDevice();

	auto path = std::string{ core::Config::GetDataPath() } + "Model\\Dragon.bin";
	auto bufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
	CANDY_ASSERT(core::FileSystem::RequestReadNoWait(path, bufferInfo));

	auto modelBin = graphic::Model::ReadAlloc(bufferInfo->m_Buffer, bufferInfo->m_BufferSize);
	CANDY_ASSERT(modelBin);
	for (const auto& readMeshInfo : modelBin->m_ReadMeshInfoList)
	{
		const u32 vertexCount = (u32)readMeshInfo.m_ReadVertexInfoList.size();
		const u32 indexCount = vertexCount;

		MeshInfo meshInfo;

		graphic::BufferStartupInfo dummyModelVertexBufferStartupInfo;
		dummyModelVertexBufferStartupInfo.setBufferStartupInfo(sizeof(ModelVertexInfo) * vertexCount);
		meshInfo.m_VertexBuffer.startup(graphicDevice, dummyModelVertexBufferStartupInfo);
		std::vector<ModelVertexInfo> modelVertexInfoList(vertexCount);
		for (u32 i = 0; i < vertexCount; ++i)
		{
			modelVertexInfoList[i].m_Position = readMeshInfo.m_ControlPointList[readMeshInfo.m_ControlPointIndexList[i]];
			modelVertexInfoList[i].m_Normal = readMeshInfo.m_ReadVertexInfoList[i].m_Normal;
			modelVertexInfoList[i].m_TexCoord0 = readMeshInfo.m_ReadVertexInfoList[i].m_TexCoord0;
			modelVertexInfoList[i].m_TexCoord1 = readMeshInfo.m_ReadVertexInfoList[i].m_TexCoord1;
		}
		meshInfo.m_VertexBuffer.store(reinterpret_cast<const std::byte*>(modelVertexInfoList.data()), sizeof(ModelVertexInfo) * vertexCount, 0);

		graphic::BufferStartupInfo dummyModelIndexBufferStartupInfo;
		dummyModelIndexBufferStartupInfo.setBufferStartupInfo(sizeof(ModelIndexType) * indexCount);
		meshInfo.m_IndexBuffer.startup(graphicDevice, dummyModelIndexBufferStartupInfo);
		std::vector<ModelIndexType> modelIndexList(indexCount);
		for (u32 i = 0; i < indexCount; ++i)
		{
			modelIndexList[i] = i;
		}
		meshInfo.m_IndexBuffer.store(reinterpret_cast<const std::byte*>(modelIndexList.data()), sizeof(ModelIndexType) * indexCount, 0);

		meshInfo.m_VertexBufferView.startup(meshInfo.m_VertexBuffer, 0, vertexCount, sizeof(ModelVertexInfo));
		meshInfo.m_IndexBufferView.startup(meshInfo.m_IndexBuffer, 0, indexCount, sizeof(ModelIndexType), ModelIndexGraphicFormat);

		meshInfo.m_Name = readMeshInfo.m_Header.m_Name;

		m_DummyModelInfo.m_MeshInfoList.push_back(meshInfo);
	}
}

void ModelResourceManager::Cleanup()
{

}

void ModelResourceManager::Add(const std::string_view _path, const ModelInfo& _info)
{
	const u32 hash = core::Fnv::Hash32(core::Path::FormatPath(_path));
	m_ModelInfoMap.insert({ hash, _info });
}

void ModelResourceManager::Remove(const std::string_view _path)
{
	const u32 hash = core::Fnv::Hash32(core::Path::FormatPath(_path));
	m_ModelInfoMap.erase(hash);
}

const ModelResourceManager::ModelInfo& ModelResourceManager::GetModelInfo(const std::string_view _path)
{
	return GetModelInfo(core::Fnv::Hash32(core::Path::FormatPath(_path)));
}

const ModelResourceManager::ModelInfo& ModelResourceManager::GetModelInfo(const u32 _hash)
{
	auto itr = m_ModelInfoMap.find(_hash);
	if (itr == m_ModelInfoMap.end())
	{
		CANDY_LOG("モデルが見つからなかったのでdummyモデルを返します");
		return m_DummyModelInfo;
	}
	return itr->second;
}

const ModelResourceManager::ModelInfo& ModelResourceManager::GetDummyModelInfo()
{
	return m_DummyModelInfo;
}

CANDY_APP_NAMESPACE_END
