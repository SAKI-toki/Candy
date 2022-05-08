#include "GraphicDefWin.h"

CANDY_NAMESPACE_BEGIN

D3D12_COMMAND_LIST_TYPE Graphic::Impl::ConvCommandListType(const COMMAND_LIST_TYPE _commandListType)
{
	switch (_commandListType)
	{
	case COMMAND_LIST_TYPE::RENDERING:	return D3D12_COMMAND_LIST_TYPE_DIRECT;
	case COMMAND_LIST_TYPE::COMPUTE:	return D3D12_COMMAND_LIST_TYPE_COMPUTE;
	}

	CANDY_LOG("未設定のコマンドリストタイプです");
	return D3D12_COMMAND_LIST_TYPE_DIRECT;
}

DXGI_FORMAT Graphic::Impl::ConvGraphicFormat(const GRAPHIC_FORMAT _graphicFormat)
{
	switch (_graphicFormat)
	{
	case GRAPHIC_FORMAT::UNKNOWN:				return DXGI_FORMAT_UNKNOWN;
	case GRAPHIC_FORMAT::R8G8B8A8_UNORM:		return DXGI_FORMAT_R8G8B8A8_UNORM;
	case GRAPHIC_FORMAT::R32G32B32A32_FLOAT:	return DXGI_FORMAT_R32G32B32A32_FLOAT;
	case GRAPHIC_FORMAT::D32_FLOAT:				return DXGI_FORMAT_D32_FLOAT;
	case GRAPHIC_FORMAT::R32_UINT:				return DXGI_FORMAT_R32_UINT;
	case GRAPHIC_FORMAT::BC1_UNORM:				return DXGI_FORMAT_BC1_UNORM;
	}

	CANDY_LOG("未設定のグラフィックフォーマットです");
	return DXGI_FORMAT_UNKNOWN;
}

u64 Graphic::Impl::GetSizeGraphicFormat(const GRAPHIC_FORMAT _graphicFormat)
{
	switch (_graphicFormat)
	{
	case GRAPHIC_FORMAT::UNKNOWN:				return 0;
	case GRAPHIC_FORMAT::R8G8B8A8_UNORM:		return 4;
	case GRAPHIC_FORMAT::R32G32B32A32_FLOAT:	return 16;
	case GRAPHIC_FORMAT::D32_FLOAT:				return 4;
	case GRAPHIC_FORMAT::R32_UINT:				return 4;
	case GRAPHIC_FORMAT::BC1_UNORM:				return 4;
	}

	CANDY_LOG("未設定のグラフィックフォーマットです");
	return 0;
}

D3D12_RESOURCE_STATES Graphic::Impl::ConvBarrierState(const BARRIER_STATE _barrierState)
{
	switch (_barrierState)
	{
	case BARRIER_STATE::COMMON:					return D3D12_RESOURCE_STATE_COMMON;
	case BARRIER_STATE::RENDER_TARGET:			return D3D12_RESOURCE_STATE_RENDER_TARGET;
	case BARRIER_STATE::PRESENT:				return D3D12_RESOURCE_STATE_PRESENT;
	case BARRIER_STATE::PIXEL_SHADER_RESOURCE:	return D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
	}

	CANDY_LOG("未設定のバリアステートです");
	return D3D12_RESOURCE_STATE_COMMON;
}

D3D12_DESCRIPTOR_HEAP_TYPE Graphic::Impl::ConvDescriptorType(const DESCRIPTOR_TYPE _descriptorType)
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

D3D12_DESCRIPTOR_RANGE_TYPE Graphic::Impl::ConvDescriptorRangeType(const DESCRIPTOR_TYPE _descriptorType)
{
	switch (_descriptorType)
	{
	case DESCRIPTOR_TYPE::CONSTANT_BUFFER:	return D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
	case DESCRIPTOR_TYPE::SHADER_RESOURCE:	return D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	case DESCRIPTOR_TYPE::UNORDERED_ACCESS:	return D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
	}

	CANDY_LOG("未設定のデスクリプタレンジタイプです");
	return D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
}

const char* Graphic::Impl::GetShaderSemanticName(const SHADER_SEMANTIC_TYPE _shaderSemanticType)
{
	switch (_shaderSemanticType)
	{
	case SHADER_SEMANTIC_TYPE::POSITION:		return "POSITION";
	case SHADER_SEMANTIC_TYPE::TEXCOORD:		return "TEXCOORD";
	case SHADER_SEMANTIC_TYPE::COLOR:			return "COLOR";
	case SHADER_SEMANTIC_TYPE::NORMAL:			return "NORMAL";
	case SHADER_SEMANTIC_TYPE::BINORMAL:		return "BINORMAL";
	case SHADER_SEMANTIC_TYPE::TANGENT:			return "TANGENT";
	case SHADER_SEMANTIC_TYPE::BLENDINDICES:	return "BLENDINDICES";
	case SHADER_SEMANTIC_TYPE::BLENDWEIGHT:		return "BLENDWEIGHT";
	}

	CANDY_LOG("未設定のシェーダーセマンティックタイプです");
	return "TEXCOORD";
}

D3D12_FILTER Graphic::Impl::ConvFilterType(const FILTER_TYPE _filterType)
{
	switch (_filterType)
	{
	case FILTER_TYPE::ANISOTROPIC:	return D3D12_FILTER_ANISOTROPIC;
	}

	CANDY_LOG("未設定のフィルタータイプです");
	return D3D12_FILTER_ANISOTROPIC;
}

D3D12_TEXTURE_ADDRESS_MODE Graphic::Impl::ConvTextureAddressMode(const TEXTURE_ADDRESS_MODE _textureAddressMode)
{
	switch (_textureAddressMode)
	{
	case TEXTURE_ADDRESS_MODE::WRAP:	return D3D12_TEXTURE_ADDRESS_MODE_WRAP;
	case TEXTURE_ADDRESS_MODE::CLAMP:	return D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
	}

	CANDY_LOG("未設定のテクスチャアドレスモードです");
	return D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
}

D3D12_SHADER_VISIBILITY Graphic::Impl::ConvShaderVisibilityType(const SHADER_VISIBILITY_TYPE _shaderVisibilityType)
{
	switch (_shaderVisibilityType)
	{
	case SHADER_VISIBILITY_TYPE::VERTEX:	return D3D12_SHADER_VISIBILITY_VERTEX;
	case SHADER_VISIBILITY_TYPE::PIXEL:		return D3D12_SHADER_VISIBILITY_PIXEL;
	case SHADER_VISIBILITY_TYPE::ALL:		return D3D12_SHADER_VISIBILITY_ALL;
	}

	CANDY_LOG("未設定のシェーダー可視タイプです");
	return D3D12_SHADER_VISIBILITY_ALL;
}

D3D12_COMPARISON_FUNC Graphic::Impl::ConvComparisonFuncType(const COMPARISON_TYPE _comparisonType)
{
	switch (_comparisonType)
	{
	case COMPARISON_TYPE::NEVER:		return D3D12_COMPARISON_FUNC_NEVER;
	case COMPARISON_TYPE::LESS:			return D3D12_COMPARISON_FUNC_LESS;
	case COMPARISON_TYPE::EQUAL:		return D3D12_COMPARISON_FUNC_EQUAL;
	case COMPARISON_TYPE::LESS_EQUAL:	return D3D12_COMPARISON_FUNC_LESS_EQUAL;
	case COMPARISON_TYPE::GREATER:		return D3D12_COMPARISON_FUNC_GREATER;
	case COMPARISON_TYPE::NOT_EQUAL:	return D3D12_COMPARISON_FUNC_NOT_EQUAL;
	case COMPARISON_TYPE::GREATER_EQUAL:return D3D12_COMPARISON_FUNC_GREATER_EQUAL;
	case COMPARISON_TYPE::ALWAYS:		return D3D12_COMPARISON_FUNC_ALWAYS;
	}

	CANDY_LOG("未設定の比較関数タイプです");
	return D3D12_COMPARISON_FUNC_NEVER;
}

D3D12_ROOT_SIGNATURE_FLAGS Graphic::Impl::ConvRootSignatureFlag(const ROOT_SIGNATURE_FLAG _rootSignatureFlag)
{
	switch (_rootSignatureFlag)
	{
	case ROOT_SIGNATURE_FLAG::NONE:									return D3D12_ROOT_SIGNATURE_FLAG_NONE;
	case ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT:	return D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	}

	CANDY_LOG("未設定のルートシグネチャフラグです");
	return D3D12_ROOT_SIGNATURE_FLAG_NONE;
}

D3D12_PRIMITIVE_TOPOLOGY Graphic::Impl::ConvPrimitiveTopology(const PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType)
{
	switch (_primitiveTopologyType)
	{
	case PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST:	return D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	case PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_STRIP:	return D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
	}

	CANDY_LOG("未設定のプリミティブトポロジータイプです");
	return D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}

CANDY_NAMESPACE_END
