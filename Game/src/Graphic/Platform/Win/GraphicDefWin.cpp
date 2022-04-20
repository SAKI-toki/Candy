#include "GraphicDefWin.h"

CANDY_NAMESPACE_BEGIN

D3D12_COMMAND_LIST_TYPE Graphic::ConvCommandListType(const COMMAND_LIST_TYPE _commandListType)
{
	switch (_commandListType)
	{
	case COMMAND_LIST_TYPE::RENDERING:	return D3D12_COMMAND_LIST_TYPE_DIRECT;
	case COMMAND_LIST_TYPE::COMPUTE:	return D3D12_COMMAND_LIST_TYPE_COMPUTE;
	}

	CANDY_LOG("���ݒ�̃R�}���h���X�g�^�C�v�ł�");
	return D3D12_COMMAND_LIST_TYPE_DIRECT;
}

DXGI_FORMAT Graphic::ConvTextureFormat(const TEXTURE_FORMAT _textureFormat)
{
	switch (_textureFormat)
	{
	case TEXTURE_FORMAT::R8G8B8A8_UNORM:	return DXGI_FORMAT_R8G8B8A8_UNORM;
	}

	CANDY_LOG("���ݒ�̃e�N�X�`���t�H�[�}�b�g�ł�");
	return DXGI_FORMAT_R8G8B8A8_UNORM;
}

CANDY_NAMESPACE_END
