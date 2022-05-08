#ifndef CANDY_GRAPHIC_BUFFER_STARTUP_INFO_IMPL_H
#define CANDY_GRAPHIC_BUFFER_STARTUP_INFO_IMPL_H

#include <Graphic/Platform/Win/GraphicDefWin.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic::Impl
{
	class BufferStartupInfoImpl
	{
	protected:
		void setBufferStartupInfo(const u64 _size);
		void setRenderTargetStartupInfo(const GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height);
		void setTextureStartupInfo(const GRAPHIC_FORMAT _graphicFormat, const u64 _width, const u64 _height);

	public:
		const D3D12_HEAP_PROPERTIES& getHeapProperties()const { return m_HeapProperties; }
		const D3D12_HEAP_PROPERTIES* getHeapPropertiesAddress()const { return &m_HeapProperties; }
		const D3D12_RESOURCE_DESC& getResourceDesc()const { return m_ResourceDesc; }
		const D3D12_RESOURCE_DESC* getResourceDescAddress()const { return &m_ResourceDesc; }
		const D3D12_CLEAR_VALUE getClearValue()const { return m_ClearValue; }
		const D3D12_CLEAR_VALUE* getClearValueAddress()const { return m_UseClearValue ? &m_ClearValue : nullptr; }
		D3D12_RESOURCE_STATES getInitState()const { return m_InitState; }

	private:
		D3D12_HEAP_PROPERTIES m_HeapProperties{};
		D3D12_RESOURCE_DESC m_ResourceDesc{};
		D3D12_CLEAR_VALUE m_ClearValue{};
		D3D12_RESOURCE_STATES m_InitState = D3D12_RESOURCE_STATE_COMMON;
		bool m_UseClearValue = false;
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_BUFFER_STARTUP_INFO_IMPL_H
