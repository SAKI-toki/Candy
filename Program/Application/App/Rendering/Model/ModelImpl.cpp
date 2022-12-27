/*****************************************************************//**
 * \file   ModelImpl.cpp
 * \brief  モデルの実装部
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "ModelImpl.h"
#include <App/Resource/Texture/TextureResourceManager.h>
#include <App/Utility/UtilityConvertPosition.h>
#include <App/Debug/Draw/String/DebugDrawString.h>

CANDY_APP_NAMESPACE_BEGIN

static constexpr float AnimFrameRate = 30.0f;

ModelImpl::ModelImpl()
{
	auto& graphicDevice = graphic::System::GetDevice();

	m_Descriptor.startup(graphicDevice, graphic::types::DESCRIPTOR_TYPE::CBV_SRV_UAV, graphic::Config::GetBackBufferCount() + 1);

	graphic::BufferStartupInfo constantBufferStartupInfo;
	constantBufferStartupInfo.setBufferStartupInfo(StaticMeshConstantBufferInfoAlignSize * graphic::Config::GetBackBufferCount());
	m_ConstantBuffer.startup(graphicDevice, constantBufferStartupInfo);
	for (s32 i = 0; i < graphic::Config::GetBackBufferCount(); ++i)
	{
		m_Descriptor.bindingConstantBuffer(graphicDevice, i, m_ConstantBuffer,
			StaticMeshConstantBufferInfoAlignSize * i, StaticMeshConstantBufferInfoAlignSize);
	}
}

ModelImpl::~ModelImpl()
{
	m_BufferViewInfoList.clear();
	m_ConstantBuffer.cleanup();
	m_Descriptor.cleanup();
}

void ModelImpl::render(const Mtx& _worldMtx, const Mtx& _rotMtx)
{
	m_StaticMeshConstantBufferInfo.worldMtx = MtxTranspose(_worldMtx);
	m_StaticMeshConstantBufferInfo.rotMtx = MtxTranspose(_rotMtx);
	m_ConstantBuffer.store(reinterpret_cast<std::byte*>(&m_StaticMeshConstantBufferInfo), sizeof(m_StaticMeshConstantBufferInfo),
		StaticMeshConstantBufferInfoAlignSize * graphic::System::GetBackBufferIndex());
}

void ModelImpl::draw(graphic::CommandList& _commandList)
{
	_commandList.setDescriptor(1, m_Descriptor);
	_commandList.registDescriptors(1, 1);
	_commandList.setDescriptorTable(1, m_Descriptor, graphic::System::GetBackBufferIndex());
	_commandList.setDescriptorTable(2, m_Descriptor, graphic::Config::GetBackBufferCount() + 0);

	s32 index = 0;
	for (const auto& bufferViewInfo : m_BufferViewInfoList)
	{
		_commandList.setVertexBuffer(0, bufferViewInfo.m_VertexBufferView);
		_commandList.registVertexBuffers(1);
		_commandList.setIndexBuffer(bufferViewInfo.m_IndexBufferView);
		_commandList.setPrimitiveTopology(graphic::types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST);
		_commandList.drawIndexedInstanced(bufferViewInfo.m_IndexBufferView.getIndexCount(), 1, 0, 0, 0);
		++index;
	}

	graphic::ResourceLifetime::Regist(m_ConstantBuffer);
}

void ModelImpl::setModel(const u32 _hash)
{
	setModelImpl(ModelResourceManager::GetModelInfo(_hash));
}


void ModelImpl::setModelImpl(std::weak_ptr<const ModelResourceManager::ModelInfo> _modelInfo)
{
	m_ModelInfoResource = _modelInfo;

	auto modelInfo = m_ModelInfoResource.lock();
	if (!modelInfo)return;

	auto& graphicDevice = graphic::System::GetDevice();

	for (const auto& meshInfo : modelInfo->m_MeshInfoList)
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
