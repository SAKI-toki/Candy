/*****************************************************************//**
 * \file   ModelImpl.h
 * \brief  モデルの実装部
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_MODEL_IMPL_H
#define CANDY_APP_MODEL_IMPL_H

#include <App/AppInclude.h>
#include <App/Resource/Model/ModelResourceManager.h>
#include <App/Defines/ModelDefine.h>

CANDY_APP_NAMESPACE_BEGIN

class ModelImpl
{
public:
	ModelImpl();
	~ModelImpl();

	void render(const Mtx& _worldMtx, const Mtx& _rotMtx);
	void draw(graphic::CommandList& _commandList);

	void setModel(const u32 _hash);

private:
	void setModelImpl(std::weak_ptr<const ModelResourceManager::ModelInfo> _modelInfo);

	struct BufferViewInfo
	{
		graphic::VertexBufferView m_VertexBufferView;
		graphic::IndexBufferView m_IndexBufferView;
	};
	std::vector<BufferViewInfo> m_BufferViewInfoList;

	graphic::Buffer m_ConstantBuffer;

	graphic::Descriptor m_Descriptor;
	StaticMeshConstantBufferInfo m_StaticMeshConstantBufferInfo;

	std::weak_ptr<const ModelResourceManager::ModelInfo> m_ModelInfoResource;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_MODEL_IMPL_H
