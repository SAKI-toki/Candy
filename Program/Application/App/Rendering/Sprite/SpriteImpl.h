/*****************************************************************//**
 * \file   SpriteImpl.h
 * \brief  Spriteの実装部
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_SPRITE_IMPL_H
#define CANDY_APP_SPRITE_IMPL_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

class SpriteImpl
{
public:
	SpriteImpl();
	~SpriteImpl();

	void render(const Vec4& _pos, const Color& _col);
	void draw(graphic::CommandList& _commandList);

	void setTexture(const u32 _hash);

private:
	graphic::Buffer m_VertexBuffer;
	graphic::Buffer m_IndexBuffer;

	graphic::VertexBufferView m_VertexBufferView;
	graphic::IndexBufferView m_IndexBufferView;

	graphic::Buffer m_ConstantBuffer;

	graphic::Descriptor m_Descriptor;
};

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_SPRITE_IMPL_H
