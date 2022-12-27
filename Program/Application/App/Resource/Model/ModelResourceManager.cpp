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
	bool CreateModelInfo(std::shared_ptr<ModelInfo>& _outModelInfo, const std::shared_ptr<core::FileSystem::BufferInfo> _bufferInfo);

	std::map<u32, std::shared_ptr<ModelInfo>> m_ModelInfoMap;
}

void ModelResourceManager::Startup()
{

}

void ModelResourceManager::Cleanup()
{
	for (auto [hash, modelInfo] : m_ModelInfoMap)
	{
		modelInfo->clear();
	}
	m_ModelInfoMap.clear();
}

void ModelResourceManager::Add(const std::string_view _path, const std::shared_ptr<core::FileSystem::BufferInfo> _bufferInfo)
{
	std::shared_ptr<ModelInfo> modelInfo;
	if (!CreateModelInfo(modelInfo, _bufferInfo))
	{
		CANDY_LOG_ERR("モデルの読み込みに失敗[{0}]", _path);
		return;
	}
	m_ModelInfoMap.insert({ core::Fnv::Hash32(core::Path::FormatPath(_path)), modelInfo });
}

void ModelResourceManager::Remove(const std::string_view _path)
{
	m_ModelInfoMap.erase(core::Fnv::Hash32(core::Path::FormatPath(_path)));
}

std::weak_ptr<const ModelResourceManager::ModelInfo> ModelResourceManager::GetModelInfo(const std::string_view _path)
{
	return GetModelInfo(core::Fnv::Hash32(core::Path::FormatPath(_path)));
}

std::weak_ptr<const ModelResourceManager::ModelInfo> ModelResourceManager::GetModelInfo(const u32 _hash)
{
	auto itr = m_ModelInfoMap.find(_hash);
	if (itr == m_ModelInfoMap.end())
	{
		CANDY_LOG("モデルが見つかりませんでした");
		return {};
	}
	return itr->second;
}

bool ModelResourceManager::CreateModelInfo(std::shared_ptr<ModelInfo>& _outModelInfo, const std::shared_ptr<core::FileSystem::BufferInfo> _bufferInfo)
{
	_outModelInfo = std::make_shared<ModelInfo>();
	if (!_outModelInfo)return false;

	auto& graphicDevice = graphic::System::GetDevice();

	auto modelBin = graphic::Model::ReadAlloc(_bufferInfo->m_Buffer, _bufferInfo->m_BufferSize);
	if (!modelBin)return false;

	for (const auto& readMeshInfo : modelBin->m_ReadMeshInfoList)
	{
		const u32 vertexCount = readMeshInfo.m_Header.m_ReadVertexInfoCount;
		const u32 indexCount = readMeshInfo.m_Header.m_VertexIndexCount;

		MeshInfo meshInfo;

		graphic::BufferStartupInfo modelVertexBufferStartupInfo;
		modelVertexBufferStartupInfo.setBufferStartupInfo(sizeof(StaticMeshVertexInfo) * vertexCount);
		meshInfo.m_VertexBuffer.startup(graphicDevice, modelVertexBufferStartupInfo);
		std::vector<StaticMeshVertexInfo> modelVertexInfoList(vertexCount);

		for (u32 i = 0; i < vertexCount; ++i)
		{
			const auto& readVertexInfo = readMeshInfo.m_ReadVertexInfoList[i];
			modelVertexInfoList[i].m_Position = readVertexInfo.m_Position;
			modelVertexInfoList[i].m_Normal = readVertexInfo.m_Normal;
			modelVertexInfoList[i].m_TexCoord0 = readVertexInfo.m_TexCoord0;
			modelVertexInfoList[i].m_TexCoord1 = readVertexInfo.m_TexCoord1;
		}
		meshInfo.m_VertexBuffer.store(reinterpret_cast<const std::byte*>(modelVertexInfoList.data()), sizeof(StaticMeshVertexInfo) * vertexCount, 0);

		graphic::BufferStartupInfo modelIndexBufferStartupInfo;
		modelIndexBufferStartupInfo.setBufferStartupInfo(sizeof(ModelIndexType) * indexCount);
		meshInfo.m_IndexBuffer.startup(graphicDevice, modelIndexBufferStartupInfo);
		std::vector<ModelIndexType> modelIndexList(indexCount);
		for (u32 i = 0; i < indexCount; ++i)
		{
			modelIndexList[i] = readMeshInfo.m_VertexIndexList[i];
		}
		meshInfo.m_IndexBuffer.store(reinterpret_cast<const std::byte*>(modelIndexList.data()), sizeof(ModelIndexType) * indexCount, 0);

		meshInfo.m_VertexBufferView.startup(meshInfo.m_VertexBuffer, 0, vertexCount, sizeof(StaticMeshVertexInfo));
		meshInfo.m_IndexBufferView.startup(meshInfo.m_IndexBuffer, 0, indexCount, sizeof(ModelIndexType), ModelIndexGraphicFormat);

		meshInfo.m_Name = readMeshInfo.m_Header.m_Name;

		_outModelInfo->m_MeshInfoList.push_back(meshInfo);
	}
	return true;
}

CANDY_APP_NAMESPACE_END
