/*****************************************************************//**
 * \file   ModelRenderingManager.cpp
 * \brief  モデルレンダリングの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "ModelRenderingManager.h"
#include <App/Component/Camera/CameraBaseComponent.h>

CANDY_APP_NAMESPACE_BEGIN

namespace ModelRenderingManager
{
	std::vector<std::shared_ptr<ModelImpl>> m_DrawModelLists[2];
	graphic::Buffer m_ConstantBuffer;
	graphic::Descriptor m_Descriptor;
	core::CriticalSection m_CriticalSection;
}

void ModelRenderingManager::Startup()
{
	m_CriticalSection.startup();

	m_Descriptor.startup(graphic::System::GetDevice(), graphic::types::DESCRIPTOR_TYPE::CBV_SRV_UAV, graphic::Config::GetBackBufferCount());
	
	graphic::BufferStartupInfo constantBufferStartupInfo;
	constantBufferStartupInfo.setBufferStartupInfo(0x100 * graphic::Config::GetBackBufferCount());
	m_ConstantBuffer.startup(graphic::System::GetDevice(), constantBufferStartupInfo);
	for (s32 i = 0; i < graphic::Config::GetBackBufferCount(); ++i)
	{
		m_Descriptor.bindingConstantBuffer(graphic::System::GetDevice(), i, m_ConstantBuffer, 0x100 * i, 0x100);
	}
}

void ModelRenderingManager::Cleanup()
{
	m_ConstantBuffer.cleanup();
	m_Descriptor.cleanup();
	m_CriticalSection.cleanup();
}

void ModelRenderingManager::Draw()
{
	auto& drawModelList = m_DrawModelLists[core::System::GetDrawIndex()];

	auto& commandList = RenderingManager::GetModelCommandList();

	commandList.setDescriptor(0, m_Descriptor);
	commandList.registDescriptors(1, 0);
	commandList.setDescriptorTable(0, m_Descriptor, graphic::System::GetBackBufferIndex());

	for (auto& drawModel : drawModelList)
	{
		if (!drawModel)continue;
		drawModel->draw(commandList);
	}

	drawModelList.clear();

	graphic::ResourceLifetime::Regist(m_ConstantBuffer);
}

void ModelRenderingManager::AddModel(const std::shared_ptr<ModelImpl>& _model)
{
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	auto& updateModelList = m_DrawModelLists[core::System::GetUpdateIndex()];
	updateModelList.push_back(_model);
}

void ModelRenderingManager::SetCamera(const CameraComponentBase& _cameraComponentBase)
{
	struct Constant
	{
		Mtx viewMtx;
		Mtx projectionMtx;
		Mtx viewProjectionMtx;
	}c;
	c.viewMtx = MtxTranspose(_cameraComponentBase.getViewMtx());
	c.projectionMtx = MtxTranspose(_cameraComponentBase.getProjectionMtx());
	c.viewProjectionMtx = MtxTranspose(_cameraComponentBase.getViewMtx() * _cameraComponentBase.getProjectionMtx());
	m_ConstantBuffer.store(reinterpret_cast<std::byte*>(&c), sizeof(c), 0x100 * graphic::System::GetBackBufferIndex());
}

CANDY_APP_NAMESPACE_END
