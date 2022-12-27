/*****************************************************************//**
 * \file   SpriteRenderingManager.cpp
 * \brief  Spriteレンダリングの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "SpriteRenderingManager.h"
#include <App/Component/Camera/CameraBaseComponent.h>

CANDY_APP_NAMESPACE_BEGIN

namespace SpriteRenderingManager
{
	std::vector<std::shared_ptr<SpriteImpl>> m_DrawSpriteLists[2];
	graphic::Buffer m_ConstantBuffer;
	graphic::Descriptor m_Descriptor;
	core::CriticalSection m_CriticalSection;
}

void SpriteRenderingManager::Startup()
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

void SpriteRenderingManager::Cleanup()
{
	m_ConstantBuffer.cleanup();
	m_Descriptor.cleanup();
	m_CriticalSection.cleanup();
}

void SpriteRenderingManager::Draw()
{
	auto& drawSpriteList = m_DrawSpriteLists[core::System::GetDrawIndex()];

	std::sort(drawSpriteList.begin(), drawSpriteList.end(),
		[](const std::shared_ptr<SpriteImpl>& _lhs, const std::shared_ptr<SpriteImpl>& _rhs)
		{
			if (!_rhs)return true;
			if (!_lhs)return false;
			return _lhs->getDrawPriority() < _rhs->getDrawPriority();
		});

	auto& commandList = RenderingManager::GetSpriteCommandList();

	commandList.setDescriptor(0, m_Descriptor);
	commandList.registDescriptors(1, 0);
	commandList.setDescriptorTable(0, m_Descriptor, graphic::System::GetBackBufferIndex());

	for (auto& drawSprite : drawSpriteList)
	{
		if (!drawSprite)continue;
		drawSprite->draw(commandList);
	}

	drawSpriteList.clear();

	graphic::ResourceLifetime::Regist(m_ConstantBuffer);
}

void SpriteRenderingManager::AddSprite(const std::shared_ptr<SpriteImpl>& _sprite)
{
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	auto& updateSpriteList = m_DrawSpriteLists[core::System::GetUpdateIndex()];
	updateSpriteList.push_back(_sprite);
}

void SpriteRenderingManager::SetCamera(const CameraComponentBase& _cameraComponentBase)
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
