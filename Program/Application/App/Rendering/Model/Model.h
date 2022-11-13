/*****************************************************************//**
 * \file   Model.h
 * \brief  モデル
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_MODEL_H
#define CANDY_APP_MODEL_H

#include <App/AppInclude.h>
#include "ModelImpl.h"

CANDY_APP_NAMESPACE_BEGIN

class Model
{
public:
	void startup();
	void cleanup();

	void render(const Mtx& _worldMtx, const Mtx& _rotMtx);

	void setModel(const std::string_view _path);
	void setModel(const u32 _hash);

private:
	std::shared_ptr<ModelImpl> m_Impl;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_MODEL_H
