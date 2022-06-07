/*****************************************************************//**
 * \file   Texture.h
 * \brief  テクスチャ
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
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();

	// アップロードテクスチャの実行
	void ExecuteUploadTexture(const Graphic::CommandQueue& _commandQueue);
	// テクスチャの作成
	void CreateTexture(Graphic::Buffer& _buffer, const std::byte* const _pixels, const u64 _size);
}

CANDY_NAMESPACE_END

#endif // CANDY_TEXTURE_H
