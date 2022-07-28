#include "UI.h"

CANDY_APP_NAMESPACE_BEGIN

namespace UI
{
	graphic::Buffer m_RenderTargetBuffer;
	graphic::Buffer m_MaskStencilBuffer;
}

void UI::Startup()
{
	auto& device = graphic::System::GetDevice();

	graphic::BufferStartupInfo bufferStartupInfo;
	bufferStartupInfo.setRenderTargetStartupInfo(graphic::types::GRAPHIC_FORMAT::R8G8B8A8_UNORM,
		graphic::Config::GetScreenWidth(), graphic::Config::GetScreenHeight());
	m_RenderTargetBuffer.startup(device, bufferStartupInfo);

	bufferStartupInfo.setDepthStencilStartupInfo(graphic::types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT,
		graphic::Config::GetScreenWidth(), graphic::Config::GetScreenHeight());
	m_MaskStencilBuffer.startup(device, bufferStartupInfo);
}

void UI::Cleanup()
{

}

void UI::Update()
{

}

void UI::Draw()
{
	//auto& commandList = Graphic::GetCommandList();
	//commandList.setRenderTargetsDepthStencil();
}

CANDY_APP_NAMESPACE_END
