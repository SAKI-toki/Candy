/*****************************************************************//**
* \file   Model.cpp
* \brief  モデル
* \author Yu Ishiyama.
* \date   2022 / 07 / 19
* ********************************************************************/

#include "Model.h"
#include "ModelRenderingManager.h"

CANDY_APP_NAMESPACE_BEGIN

void Model::startup()
{
	m_Impl = std::make_shared<ModelImpl>();
}

void Model::cleanup()
{
	m_Impl.reset();
}

void Model::render(const Mtx& _worldMtx, const Mtx& _rotMtx)
{
	if (!m_Impl)return;

	m_Impl->render(_worldMtx, _rotMtx);
	ModelRenderingManager::AddModel(m_Impl);
}

void Model::setModel(const std::string_view _path)
{
	setModel(core::Fnv::Hash32(core::Path::FormatPath(_path)));
}

void Model::setModel(const u32 _hash)
{
	m_Impl->setModel(_hash);
}

CANDY_APP_NAMESPACE_END
