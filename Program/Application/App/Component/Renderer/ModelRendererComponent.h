/*****************************************************************//**
 * \file   ModelRendererComponent.h
 * \brief  Spriteレンダラーコンポーネント
 * \author Yu Ishiyama.
 * \date   2022/08/27
 *********************************************************************/

#ifndef CANDY_APP_MODEL_RENDERER_COMPONENT_H
#define CANDY_APP_MODEL_RENDERER_COMPONENT_H

#include <App/Component/ComponentHeaderInclude.h>
#include "RendererBaseComponent.h"
#include <App/Rendering/Model/Model.h>

CANDY_APP_NAMESPACE_BEGIN

class ModelRendererComponent : public RendererComponentBase
{
	CANDY_COMPONENT_DECLARE(ModelRendererComponent, RendererComponentBase);

public:
	void startupImpl()override;
	void cleanupImpl()override;
	void renderImpl()override;

private:
	Model m_Model;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_MODEL_RENDERER_COMPONENT_H
