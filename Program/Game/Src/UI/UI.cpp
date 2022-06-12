#include "UI.h"
#include <Graphic/Graphic.h>
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/Buffer/GraphicBuffer.h>

CANDY_NAMESPACE_BEGIN

namespace UI
{
	Graphic::Buffer m_RenderTargetBuffer;
	Graphic::Buffer m_MaskStencilBuffer;
}

void UI::Startup()
{
	auto& device = Graphic::GetDevice();

	Graphic::BufferStartupInfo bufferStartupInfo;
	bufferStartupInfo.setRenderTargetStartupInfo(Graphic::GRAPHIC_FORMAT::R8G8B8A8_UNORM,
		Graphic::GetScreenWidth(), Graphic::GetScreenHeight());
	m_RenderTargetBuffer.startup(device, bufferStartupInfo);

	bufferStartupInfo.setDepthStencilStartupInfo(Graphic::GRAPHIC_FORMAT::D24_UNORM_S8_UINT,
		Graphic::GetScreenWidth(), Graphic::GetScreenHeight());
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

CANDY_NAMESPACE_END
