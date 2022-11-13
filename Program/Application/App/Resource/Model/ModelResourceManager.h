/*****************************************************************//**
 * \file   ModelResourceManager.h
 * \brief  モデルリソースの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_MODEL_RESOURCE_MANAGER_H
#define CANDY_APP_MODEL_RESOURCE_MANAGER_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace ModelResourceManager
{
	struct MeshInfo
	{
		graphic::Buffer m_VertexBuffer;
		graphic::Buffer m_IndexBuffer;
		graphic::VertexBufferView m_VertexBufferView;
		graphic::IndexBufferView m_IndexBufferView;

		std::string m_Name;
	};

	struct ModelInfo
	{
		std::vector<MeshInfo> m_MeshInfoList;
	};

	void Startup();
	void Cleanup();

	void Add(const std::string_view _path, const ModelInfo& _info);
	void Remove(const std::string_view _path);

	const ModelInfo& GetModelInfo(const std::string_view _path);
	const ModelInfo& GetModelInfo(const u32 _hash);

	const ModelInfo& GetDummyModelInfo();
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_MODEL_RESOURCE_MANAGER_H
