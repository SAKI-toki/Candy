/*****************************************************************//**
 * \file   ModelImpl.cpp
 * \brief  モデルの実装部
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "ModelImpl.h"
#include <App/Resource/Texture/TextureResourceManager.h>
#include <App/Utility/UtilityConvertPosition.h>

CANDY_APP_NAMESPACE_BEGIN

ModelImpl::ModelImpl()
{
	auto& graphicDevice = graphic::System::GetDevice();

	m_Descriptor.startup(graphicDevice, graphic::types::DESCRIPTOR_TYPE::CBV_SRV_UAV, graphic::Config::GetBackBufferCount() + 1);

	graphic::BufferStartupInfo constantBufferStartupInfo;
	constantBufferStartupInfo.setBufferStartupInfo(0x100 * graphic::Config::GetBackBufferCount());
	m_ConstantBuffer.startup(graphicDevice, constantBufferStartupInfo);
	for (s32 i = 0; i < graphic::Config::GetBackBufferCount(); ++i)
	{
		m_Descriptor.bindingConstantBuffer(graphicDevice, i, m_ConstantBuffer, 0x100 * i, 0x100);
	}

	setModelImpl(ModelResourceManager::GetDummyModelInfo());
}

ModelImpl::~ModelImpl()
{
	m_BufferViewInfoList.clear();
	m_ConstantBuffer.cleanup();
	m_Descriptor.cleanup();
}

void ModelImpl::render(const Mtx& _worldMtx, const Mtx& _rotMtx)
{
	struct Constant
	{
		Mtx worldMtx;
		Mtx rotMtx;
	}c;
	MtxTranspose(c.worldMtx, _worldMtx);
	MtxTranspose(c.rotMtx, _rotMtx);
	m_ConstantBuffer.store(reinterpret_cast<std::byte*>(&c), sizeof(c), 0x100 * graphic::System::GetBackBufferIndex());
}

void ModelImpl::draw(graphic::CommandList& _commandList)
{
	_commandList.setDescriptor(0, m_Descriptor);
	_commandList.registDescriptors(1, 0);
	_commandList.setDescriptorTable(1, m_Descriptor, graphic::System::GetBackBufferIndex());
	_commandList.setDescriptorTable(2, m_Descriptor, graphic::Config::GetBackBufferCount() + 0);

	for (const auto& bufferViewInfo : m_BufferViewInfoList)
	{
		_commandList.setVertexBuffer(0, bufferViewInfo.m_VertexBufferView);
		_commandList.registVertexBuffers(1);
		_commandList.setIndexBuffer(bufferViewInfo.m_IndexBufferView);
		_commandList.setPrimitiveTopology(graphic::types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
		_commandList.drawIndexedInstanced(bufferViewInfo.m_IndexBufferView.getIndexCount(), 1, 0, 0, 0);
	}

	graphic::ResourceLifetime::Regist(m_ConstantBuffer);
}

void ModelImpl::setModel(const u32 _hash)
{
	setModelImpl(ModelResourceManager::GetModelInfo(_hash));
}

void ModelImpl::setModelImpl(const ModelResourceManager::ModelInfo& _modelInfo)
{
	auto& graphicDevice = graphic::System::GetDevice();

	for (const auto& meshInfo : _modelInfo.m_MeshInfoList)
	{
		BufferViewInfo bufferViewInfo;
		bufferViewInfo.m_VertexBufferView = meshInfo.m_VertexBufferView;
		bufferViewInfo.m_IndexBufferView = meshInfo.m_IndexBufferView;
		auto& textureInfo = TextureResourceManager::GetDummyTextureInfo();
		m_Descriptor.bindingTexture2D(graphicDevice, graphic::Config::GetBackBufferCount(), textureInfo.m_Buffer, textureInfo.m_Format, textureInfo.m_MipMapCount);
		m_BufferViewInfoList.push_back(bufferViewInfo);
	}
}

CANDY_APP_NAMESPACE_END
