#include "GraphicDefWin.h"
#include "GraphicImpl.h"

CANDY_NAMESPACE_BEGIN

D3D12_COMMAND_LIST_TYPE Graphic::ConvCommandListType(const COMMAND_LIST_TYPE _commandListType)
{
	switch (_commandListType)
	{
	case COMMAND_LIST_TYPE::RENDERING:	return D3D12_COMMAND_LIST_TYPE_DIRECT;
	case COMMAND_LIST_TYPE::COMPUTE:	return D3D12_COMMAND_LIST_TYPE_COMPUTE;
	}

	CANDY_LOG("未設定のコマンドリストタイプです");
	return D3D12_COMMAND_LIST_TYPE_DIRECT;
}

DXGI_FORMAT Graphic::ConvTextureFormat(const TEXTURE_FORMAT _textureFormat)
{
	switch (_textureFormat)
	{
	case TEXTURE_FORMAT::R8G8B8A8_UNORM:	return DXGI_FORMAT_R8G8B8A8_UNORM;
	}

	CANDY_LOG("未設定のテクスチャフォーマットです");
	return DXGI_FORMAT_R8G8B8A8_UNORM;
}

D3D12_RESOURCE_STATES Graphic::ConvBarrierState(const BARRIER_STATE _barrierState)
{
	switch (_barrierState)
	{
	case BARRIER_STATE::COMMON:			return D3D12_RESOURCE_STATE_COMMON;
	case BARRIER_STATE::RENDER_TARGET:	return D3D12_RESOURCE_STATE_RENDER_TARGET;
	case BARRIER_STATE::PRESENT:		return D3D12_RESOURCE_STATE_PRESENT;
	}

	CANDY_LOG("未設定のバリアステートです");
	return D3D12_RESOURCE_STATE_COMMON;
}

D3D12_DESCRIPTOR_HEAP_TYPE Graphic::ConvDescriptorType(const DESCRIPTOR_TYPE _descriptorType)
{
	switch (_descriptorType)
	{
	case DESCRIPTOR_TYPE::CONSTANT_BUFFER:	return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	case DESCRIPTOR_TYPE::SHADER_RESOURCE:	return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	case DESCRIPTOR_TYPE::UNORDERED_ACCESS:	return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	case DESCRIPTOR_TYPE::RENDER_TARGET:	return D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
	}

	CANDY_LOG("未設定のデスクリプタタイプです");
	return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
}

s32 Graphic::GetDesciptorHandleIncrementSize(const D3D12_DESCRIPTOR_HEAP_TYPE _descriptorType)
{
	return Graphic::Impl::GetDesciptorHandleIncrementSize(_descriptorType);
}

CANDY_NAMESPACE_END
