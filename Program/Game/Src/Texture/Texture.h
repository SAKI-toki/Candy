/*****************************************************************//**
 * \file   Texture.h
 * \brief  �e�N�X�`��
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_TEXTURE_H
#define CANDY_TEXTURE_H

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
	class Buffer;
	class CommandQueue;
}

namespace Texture
{
	// ������
	void Startup();
	// �j��
	void Cleanup();

	// �A�b�v���[�h�e�N�X�`���̎��s
	void ExecuteUploadTexture(const Graphic::CommandQueue& _commandQueue);
	// �e�N�X�`���̍쐬
	void CreateTexture(Graphic::Buffer& _buffer, const std::byte* const _pixels, const u64 _size);
}

CANDY_NAMESPACE_END

#endif // CANDY_TEXTURE_H
