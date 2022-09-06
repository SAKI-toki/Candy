/*****************************************************************//**
 * \file   RenderingPass_EndFrame.h
 * \brief  フレーム終了レンダリングパス
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_RENDERING_PASS_END_FRAME_H
#define CANDY_APP_RENDERING_PASS_END_FRAME_H

#include <App/AppInclude.h>
#include "RenderingPassBase.h"

CANDY_APP_NAMESPACE_BEGIN

namespace RenderingManager
{
	class EndFramePass : public PassBase
	{
	public:
		void startup()override;
		void cleanup()override;

		void beginPass(graphic::CommandList& _commandList)override;

	private:
		graphic::Descriptor m_Descriptor;
		graphic::RootSignature m_RootSignature;
		graphic::Pipeline m_Pipeline;
		graphic::Buffer m_VertexBuffer;
		graphic::Buffer m_IndexBuffer;
		graphic::VertexBufferView m_VertexBufferView;
		graphic::IndexBufferView m_IndexBufferView;
	};
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_RENDERING_PASS_END_FRAME_H
