/*****************************************************************//**
 * \file   SpriteImpl.cpp
 * \brief  Spriteの実装部
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "SpriteImpl.h"

CANDY_APP_NAMESPACE_BEGIN

SpriteImpl::SpriteImpl()
{
	struct VertexInfo
	{
		Vec4 pos, texcoord;
	};

	auto& graphicDevice = graphic::System::GetDevice();

	graphic::BufferStartupInfo vertexBufferStartupInfo;
	vertexBufferStartupInfo.setBufferStartupInfo(sizeof(VertexInfo) * 4);
	m_VertexBuffer.startup(graphicDevice, vertexBufferStartupInfo);
	graphic::BufferStartupInfo indexBufferStartupInfo;
	indexBufferStartupInfo.setBufferStartupInfo(sizeof(u16) * 6);
	m_IndexBuffer.startup(graphicDevice, indexBufferStartupInfo);
	constexpr f32 size = 0.5f;
	VertexInfo vertices[4] =
	{
		{ Vec4{ -size / 16.0f * 9.0f, +size, 0.0f }, Vec4{ 0.0f, 0.0f, 0.0f } },
		{ Vec4{ +size / 16.0f * 9.0f, +size, 0.0f }, Vec4{ 1.0f, 0.0f, 0.0f } },
		{ Vec4{ +size / 16.0f * 9.0f, -size, 0.0f }, Vec4{ 1.0f, 1.0f, 0.0f } },
		{ Vec4{ -size / 16.0f * 9.0f, -size, 0.0f }, Vec4{ 0.0f, 1.0f, 0.0f } },
	};
	m_VertexBuffer.store(reinterpret_cast<std::byte*>(vertices), sizeof(VertexInfo) * 4, 0);
	u16 indices[6] = { 0, 1, 2, 0, 2, 3 };
	m_IndexBuffer.store(reinterpret_cast<std::byte*>(indices), sizeof(u16) * 6, 0);

	m_VertexBufferView.startup(m_VertexBuffer, 0, 4, sizeof(VertexInfo));
	m_IndexBufferView.startup(m_IndexBuffer, 0, 6, sizeof(u16), graphic::types::GRAPHIC_FORMAT::R16_UINT);

	m_Descriptor.startup(graphic::System::GetDevice(), graphic::types::DESCRIPTOR_TYPE::CBV_SRV_UAV, graphic::Config::GetBackBufferCount() + 1);

	graphic::BufferStartupInfo constantBufferStartupInfo;
	constantBufferStartupInfo.setBufferStartupInfo(0x100 * graphic::Config::GetBackBufferCount());
	m_ConstantBuffer.startup(graphic::System::GetDevice(), constantBufferStartupInfo);
	for (s32 i = 0; i < graphic::Config::GetBackBufferCount(); ++i)
	{
		m_Descriptor.bindingConstantBuffer(graphic::System::GetDevice(), i, m_ConstantBuffer, 0x100 * i, 0x100);
	}

	auto& textureInfo = TextureManager::GetDummyTextureInfo();
	m_Descriptor.bindingTexture2D(graphicDevice, graphic::Config::GetBackBufferCount(), textureInfo.m_Buffer, textureInfo.m_Format);
}

SpriteImpl::~SpriteImpl()
{
	m_VertexBuffer.cleanup();
	m_IndexBuffer.cleanup();
	m_VertexBufferView.cleanup();
	m_IndexBufferView.cleanup();
	m_ConstantBuffer.cleanup();
}

void SpriteImpl::render(const Vec4& _pos, const Color& _col)
{
	struct Constant
	{
		Vec4 pos, col;
	}c;
	c.pos = _pos;
	c.col = _col;
	m_ConstantBuffer.store(reinterpret_cast<std::byte*>(&c), sizeof(c), 0x100 * graphic::System::GetNextBackBufferIndex());
}

void SpriteImpl::draw(graphic::CommandList& _commandList)
{
	_commandList.setDescriptor(0, m_Descriptor);
	_commandList.registDescriptors(1, 0);
	_commandList.setDescriptorTable(0, m_Descriptor, graphic::System::GetBackBufferIndex());
	_commandList.setDescriptorTable(1, m_Descriptor, graphic::Config::GetBackBufferCount() + 0);

	_commandList.setVertexBuffer(0, m_VertexBufferView);
	_commandList.registVertexBuffers(1);
	_commandList.setIndexBuffer(m_IndexBufferView);
	_commandList.setPrimitiveTopology(graphic::types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
	_commandList.drawIndexedInstanced(m_IndexBufferView.getIndexCount(), 1, 0, 0, 0);

	graphic::ResourceLifetime::Regist(m_VertexBuffer);
	graphic::ResourceLifetime::Regist(m_IndexBuffer);
	graphic::ResourceLifetime::Regist(m_ConstantBuffer);
}

void SpriteImpl::setTexture(const u32 _hash)
{
	auto& graphicDevice = graphic::System::GetDevice();
	auto& textureInfo = TextureManager::GetTextureInfo(_hash);

	m_Descriptor.bindingRenderTarget(graphicDevice, graphic::Config::GetBackBufferCount(), textureInfo.m_Buffer, textureInfo.m_Format);
}

CANDY_APP_NAMESPACE_END
