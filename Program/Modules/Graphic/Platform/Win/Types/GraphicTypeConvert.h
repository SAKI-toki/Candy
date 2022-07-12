/*****************************************************************//**
 * \file   GraphicTypeImpl.h
 * \brief  graphicのタイプの実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/13
 *********************************************************************/

#ifndef CANDY_GRAPHIC_TYPE_IMPL_H
#define CANDY_GRAPHIC_TYPE_IMPL_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace impl
{
	D3D12_COMMAND_LIST_TYPE ConvCommandListType(const types::COMMAND_LIST_TYPE _commandListType);
	DXGI_FORMAT ConvGraphicFormat(const types::GRAPHIC_FORMAT _graphicFormat);
	u64 GetSizeGraphicFormat(const types::GRAPHIC_FORMAT _graphicFormat);
	D3D12_RESOURCE_STATES ConvBarrierState(const types::BARRIER_STATE _barrierState);
	D3D12_DESCRIPTOR_HEAP_TYPE ConvDescriptorType(const types::DESCRIPTOR_TYPE _descriptorType);
	D3D12_DESCRIPTOR_RANGE_TYPE ConvDescriptorRangeType(const types::DESCRIPTOR_RANGE_TYPE _descriptorRangeType);
	const char* GetShaderSemanticName(const types::SHADER_SEMANTIC_TYPE _shaderSemanticType);
	D3D12_FILTER ConvFilterType(const types::FILTER_TYPE _filterType);
	D3D12_TEXTURE_ADDRESS_MODE ConvTextureAddressMode(const types::TEXTURE_ADDRESS_MODE _textureAddressMode);
	D3D12_SHADER_VISIBILITY ConvShaderVisibilityType(const types::SHADER_VISIBILITY_TYPE _shaderVisibilityType);
	D3D12_COMPARISON_FUNC ConvComparisonFuncType(const types::COMPARISON_TYPE _comparisonType);
	D3D12_ROOT_SIGNATURE_FLAGS ConvRootSignatureFlag(const types::ROOT_SIGNATURE_FLAG _rootSignatureFlag);
	D3D12_PRIMITIVE_TOPOLOGY ConvPrimitiveTopology(const types::PRIMITIVE_TOPOLOGY_TYPE _primitiveTopologyType);
	D3D12_FILL_MODE ConvFillMode(const types::FILL_MODE _fillMode);
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_TYPE_IMPL_H

