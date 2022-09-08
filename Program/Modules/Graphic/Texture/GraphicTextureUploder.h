/*****************************************************************//**
 * \file   TextureUploder.h
 * \brief  テクスチャのアップローダー
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#ifndef CANDY_GRAPHIC_TEXTURE_H
#define CANDY_GRAPHIC_TEXTURE_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Buffer;
class CommandQueue;

namespace TextureUploder
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();

	// アップロードテクスチャの実行
	void ExecuteUploadTexture(const CommandQueue& _commandQueue);
	// テクスチャの作成
	void CreateTexture(Buffer& _buffer, const std::byte* const _pixels, const u64 _size);
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_TEXTURE_H
