/*****************************************************************//**
 * \file   RenderingPass_Sprite.h
 * \brief  スプライトレンダリングパス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_RENDERING_PASS_SPRITE_H
#define CANDY_APP_RENDERING_PASS_SPRITE_H

#include <App/AppInclude.h>
#include "RenderingPassBase.h"

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	class SpritePass : public PassBase
	{
	public:
		void startup()override;
		void cleanup()override;

		void beginPass(graphic::CommandList& _commandList)override;

	private:
		graphic::RootSignature m_RootSignature;
		graphic::Pipeline m_Pipeline;
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_RENDERING_PASS_SPRITE_H
