#ifndef CANDY_GRAPHIC_DEF_WIN_H
#define CANDY_GRAPHIC_DEF_WIN_H

#include <Graphic/GraphicDef.h>

CANDY_NAMESPACE_BEGIN

#define CANDY_ASSERT_HRESULT(EXPR) CANDY_ASSERT(SUCCEEDED(EXPR))

namespace Graphic
{
	D3D12_COMMAND_LIST_TYPE ConvCommandListType(const COMMAND_LIST_TYPE _commandListType);
	DXGI_FORMAT ConvGraphicFormat(const GRAPHIC_FORMAT _graphicFormat);
	D3D12_RESOURCE_STATES ConvBarrierState(const BARRIER_STATE _barrierState);
	D3D12_DESCRIPTOR_HEAP_TYPE ConvDescriptorType(const DESCRIPTOR_TYPE _descriptorType);
	D3D12_DESCRIPTOR_RANGE_TYPE ConvDescriptorRangeType(const DESCRIPTOR_TYPE _descriptorType);
	const char* GetShaderSemanticName(const SHADER_SEMANTIC_TYPE _shaderSemanticType);
	D3D12_FILTER ConvFilterType(const FILTER_TYPE _filterType);
	D3D12_SHADER_VISIBILITY ConvShaderVisibilityType(const SHADER_VISIBILITY_TYPE _shaderVisibilityType);
	D3D12_COMPARISON_FUNC ConvComparisonFuncType(const COMPARISON_TYPE _comparisonType);

	s32 GetDesciptorHandleIncrementSize(const D3D12_DESCRIPTOR_HEAP_TYPE _descriptorType);
}

CANDY_NAMESPACE_END

#endif // CANDY_GRAPHIC_DEF_WIN_H