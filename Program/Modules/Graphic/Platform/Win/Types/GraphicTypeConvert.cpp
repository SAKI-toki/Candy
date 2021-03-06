#include "GraphicTypeConvert.h"

CANDY_GRAPHIC_NAMESPACE_BEGIN

D3D12_COMMAND_LIST_TYPE impl::ConvCommandListType(const types::COMMAND_LIST_TYPE _commandListType)
{
	switch (_commandListType)
	{
	case types::COMMAND_LIST_TYPE::RENDERING:	return D3D12_COMMAND_LIST_TYPE_DIRECT;
	case types::COMMAND_LIST_TYPE::COMPUTE:		return D3D12_COMMAND_LIST_TYPE_COMPUTE;
	}

	CANDY_LOG("未設定のコマンドリストタイプです");
	return D3D12_COMMAND_LIST_TYPE_DIRECT;
}

DXGI_FORMAT impl::ConvGraphicFormat(const types::GRAPHIC_FORMAT _graphicFormat)
{
	switch (_graphicFormat)
	{
	case types::GRAPHIC_FORMAT::UNKNOWN:			return DXGI_FORMAT_UNKNOWN;
	case types::GRAPHIC_FORMAT::R8G8B8A8_UNORM:		return DXGI_FORMAT_R8G8B8A8_UNORM;
	case types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT:	return DXGI_FORMAT_R32G32B32A32_FLOAT;
	case types::GRAPHIC_FORMAT::R16_UINT:			return DXGI_FORMAT_R16_UINT;
	case types::GRAPHIC_FORMAT::A8_UINT:			return DXGI_FORMAT_A8_UNORM;
	case types::GRAPHIC_FORMAT::D32_FLOAT:			return DXGI_FORMAT_D32_FLOAT;
	case types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT:	return DXGI_FORMAT_D24_UNORM_S8_UINT;
	case types::GRAPHIC_FORMAT::R32_UINT:			return DXGI_FORMAT_R32_UINT;
	case types::GRAPHIC_FORMAT::BC1_UNORM:			return DXGI_FORMAT_BC1_UNORM;
	case types::GRAPHIC_FORMAT::BC1_UNORM_SRGB:		return DXGI_FORMAT_BC1_UNORM_SRGB;
	case types::GRAPHIC_FORMAT::BC3_UNORM:			return DXGI_FORMAT_BC3_UNORM;
	case types::GRAPHIC_FORMAT::BC3_UNORM_SRGB:		return DXGI_FORMAT_BC3_UNORM_SRGB;
	}

	CANDY_LOG("未設定のグラフィックフォーマットです");
	return DXGI_FORMAT_UNKNOWN;
}

u64 impl::GetSizeGraphicFormat(const types::GRAPHIC_FORMAT _graphicFormat)
{
	switch (_graphicFormat)
	{
	case types::GRAPHIC_FORMAT::UNKNOWN:			return 0;
	case types::GRAPHIC_FORMAT::R8G8B8A8_UNORM:		return 4;
	case types::GRAPHIC_FORMAT::R32G32B32A32_FLOAT:	return 16;
	case types::GRAPHIC_FORMAT::R16_UINT:			return 2;
	case types::GRAPHIC_FORMAT::D32_FLOAT:			return 4;
	case types::GRAPHIC_FORMAT::D24_UNORM_S8_UINT:	return 4;
	case types::GRAPHIC_FORMAT::R32_UINT:			return 4;
	case types::GRAPHIC_FORMAT::BC1_UNORM:			return 4;
	case types::GRAPHIC_FORMAT::BC1_UNORM_SRGB:		return 4;
	case types::GRAPHIC_FORMAT::BC3_UNORM:			return 8;
	case types::GRAPHIC_FORMAT::BC3_UNORM_SRGB:		return 8;
	}

	CANDY_LOG("未設定のグラフィックフォーマットです");
	return 0;
}

D3D12_RESOURCE_STATES impl::ConvBarrierState(const types::BARRIER_STATE _barrierState)
{
	switch (_barrierState)
	{
	case types::BARRIER_STATE::COMMON:					return D3D12_RESOURCE_STATE_COMMON;
	case types::BARRIER_STATE::RENDER_TARGET:			return D3D12_RESOURCE_STATE_RENDER_TARGET;
	case types::BARRIER_STATE::PRESENT:					return D3D12_RESOURCE_STATE_PRESENT;
	case types::BARRIER_STATE::PIXEL_SHADER_RESOURCE:	return D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
	case types::BARRIER_STATE::CONSTANT_BUFFER:			return D3D12_RESOURCE_STATE_VERTEX_AND_CONSTANT_BUFFER;
	case types::BARRIER_STATE::COPY_DEST:				return D3D12_RESOURCE_STATE_COPY_DEST;
	case types::BARRIER_STATE::COPY_SOURCE:				return D3D12_RESOURCE_STATE_COPY_SOURCE;
	}

	CANDY_LOG("未設定のバリアステートです");
	return D3D12_RESOURCE_STATE_COMMON;
}

D3D12_DESCRIPTOR_HEAP_TYPE impl::ConvDescriptorType(const types::DESCRIPTOR_TYPE _descriptorType)
{
	switch (_descriptorType)
	{
	case types::DESCRIPTOR_TYPE::CBV_SRV_UAV:	return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	case types::DESCRIPTOR_TYPE::RENDER_TARGET:	return D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
	case types::DESCRIPTOR_TYPE::DEPTH_STENCIL:	return D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
	}

	CANDY_LOG("未設定のデスクリプタタイプです");
	return D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
}

D3D12_DESCRIPTOR_RANGE_TYPE impl::ConvDescriptorRangeType(const types::DESCRIPTOR_RANGE_TYPE _descriptorRangeType)
{
	switch (_descriptorRangeType)
	{
	case types::DESCRIPTOR_RANGE_TYPE::CONSTANT_BUFFER:		return D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
	case types::DESCRIPTOR_RANGE_TYPE::SHADER_RESOURCE:		return D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	case types::DESCRIPTOR_RANGE_TYPE::UNORDERED_ACCESS:	return D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
	}

	CANDY_LOG("未設定のデスクリプタレンジタイプです");
	return D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
}

const char* impl::GetShaderSemanticName(const types::SHADER_SEMANTIC_TYPE _shaderSemanticType)
{
	switch (_shaderSemanticType)
	{
	case types::SHADER_SEMANTIC_TYPE::POSITION:		return "POSITION";
	case types::SHADER_SEMANTIC_TYPE::TEXCOORD:		return "TEXCOORD";
	case types::SHADER_SEMANTIC_TYPE::COLOR:		return "COLOR";
	case types::SHADER_SEMANTIC_TYPE::NORMAL:		return "NORMAL";
	case types::SHADER_SEMANTIC_TYPE::BINORMAL:		return "BINORMAL";
	case types::SHADER_SEMANTIC_TYPE::TANGENT:		return "TANGENT";
	case types::SHADER_SEMANTIC_TYPE::BLENDINDICES:	return "BLENDINDICES";
	case types::SHADER_SEMANTIC_TYPE::BLENDWEIGHT:	return "BLENDWEIGHT";
	}

	CANDY_LOG("未設定のシェーダーセマンティックタイプです");
	return "TEXCOORD";
}

D3D12_FILTER impl::ConvFilterType(const types::FILTER_TYPE _filterType)
{
	switch (_filterType)
	{
	case types::FILTER_TYPE::ANISOTROPIC:	return D3D12_FILTER_ANISOTROPIC;
	}

	CANDY_LOG("未設定のフィルタータイプです");
	return D3D12_FILTER_ANISOTROPIC;
}

D3D12_TEXTURE_ADDRESS_MODE impl::ConvTextureAddressMode(const types::TEXTURE_ADDRESS_MODE _textureAddressMode)
{
	switch (_textureAddressMode)
	{
	case types::TEXTURE_ADDRESS_MODE::WRAP:		return D3D12_TEXTURE_ADDRESS_MODE_WRAP;
	case types::TEXTURE_ADDRESS_MODE::CLAMP:	return D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
	}

	CANDY_LOG("未設定のテクスチャアドレスモードです");
	return D3D12_TEXTURE_ADDRESS_MODE_CLAMP;
}

D3D12_SHADER_VISIBILITY impl::ConvShaderVisibilityType(const types::SHADER_VISIBILITY_TYPE _shaderVisibilityType)
{
	switch (_shaderVisibilityType)
	{
	case types::SHADER_VISIBILITY_TYPE::VERTEX:	return D3D12_SHADER_VISIBILITY_VERTEX;
	case types::SHADER_VISIBILITY_TYPE::PIXEL:	return D3D12_SHADER_VISIBILITY_PIXEL;
	case types::SHADER_VISIBILITY_TYPE::ALL:	return D3D12_SHADER_VISIBILITY_ALL;
	}

	CANDY_LOG("未設定のシェーダー可視タイプです");
	return D3D12_SHADER_VISIBILITY_ALL;
}

D3D12_COMPARISON_FUNC impl::ConvComparisonFuncType(const types::COMPARISON_TYPE _comparisonType)
{
	switch (_comparisonType)
	{
	case types::COMPARISON_TYPE::NEVER:			return D3D12_COMPARISON_FUNC_NEVER;
	case types::COMPARISON_TYPE::LESS:			return D3D12_COMPARISON_FUNC_LESS;
	case types::COMPARISON_TYPE::EQUAL:			return D3D12_COMPARISON_FUNC_EQUAL;
	case types::COMPARISON_TYPE::LESS_EQUAL:	return D3D12_COMPARISON_FUNC_LESS_EQUAL;
	case types::COMPARISON_TYPE::GREATER:		return D3D12_COMPARISON_FUNC_GREATER;
	case types::COMPARISON_TYPE::NOT_EQUAL:		return D3D12_COMPARISON_FUNC_NOT_EQUAL;
	case types::COMPARISON_TYPE::GREATER_EQUAL:	return D3D12_COMPARISON_FUNC_GREATER_EQUAL;
	case types::COMPARISON_TYPE::ALWAYS:		return D3D12_COMPARISON_FUNC_ALWAYS;
	}

	CANDY_LOG("未設定の比較関数タイプです");
	return D3D12_COMPARISON_FUNC_NEVER;
}

D3D12_ROOT_SIGNATURE_FLAGS impl::ConvRootSignatureFlag(const types::ROOT_SIGNATURE_FLAG _rootSignatureFlag)
{
	switch (_rootSignatureFlag)
	{
	case types::ROOT_SIGNATURE_FLAG::NONE:									return D3D12_ROOT_SIGNATURE_FLAG_NONE;
	case types::ROOT_SIGNATURE_FLAG::ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT:	return D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT;
	}

	CANDY_LOG("未設定のルートシグネチャフラグです");
	return D3D12_ROOT_SIGNATURE_FLAG_NONE;
}

D3D12_PRIMITIVE_TOPOLOGY impl::ConvPrimitiveTopology(const types::PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType)
{
	switch (_primitiveTopologyType)
	{
	case types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_LIST:		return D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	case types::PRIMITIVE_TOPOLOGY_TYPE::TRIANGLE_STRIP:	return D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
	}

	CANDY_LOG("未設定のプリミティブトポロジータイプです");
	return D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
}

D3D12_FILL_MODE impl::ConvFillMode(const types::FILL_MODE _fillMode)
{
	switch (_fillMode)
	{
	case types::FILL_MODE::SOLID:		return D3D12_FILL_MODE_SOLID;
	case types::FILL_MODE::WIREFRAME:	return D3D12_FILL_MODE_WIREFRAME;
	}

	CANDY_LOG("未設定のフィルモードです");
	return D3D12_FILL_MODE_SOLID;
}

CANDY_GRAPHIC_NAMESPACE_END
