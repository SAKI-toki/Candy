/*****************************************************************//**
 * \file   ModelRenderingManager.h
 * \brief  モデルレンダリングの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_MODEL_RENDERING_MANAGER_H
#define CANDY_APP_MODEL_RENDERING_MANAGER_H

#include <App/AppInclude.h>
#include "ModelImpl.h"

CANDY_APP_NAMESPACE_BEGIN

class CameraComponentBase;

namespace ModelRenderingManager
{
	void Startup();
	void Cleanup();

	void Draw();

	void AddModel(const std::shared_ptr<ModelImpl>& _model);
	void SetCamera(const CameraComponentBase& _cameraComponentBase);
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_MODEL_RENDERING_MANAGER_H
