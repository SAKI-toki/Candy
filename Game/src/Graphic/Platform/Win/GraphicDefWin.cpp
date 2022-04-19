#include "GraphicDefWin.h"

CANDY_NAMESPACE_BEGIN

D3D12_COMMAND_LIST_TYPE Graphic::ConvCommandListType(const COMMAND_LIST_TYPE _commandListType)
{
	switch (_commandListType)
	{
	case COMMAND_LIST_TYPE::RENDERING:	return D3D12_COMMAND_LIST_TYPE_DIRECT;
	case COMMAND_LIST_TYPE::COMPUTE:	return D3D12_COMMAND_LIST_TYPE_COMPUTE;
	default:							CANDY_LOG("未設定のコマンドリストタイプです"); break;
	}

	return D3D12_COMMAND_LIST_TYPE_DIRECT;
}

CANDY_NAMESPACE_END
