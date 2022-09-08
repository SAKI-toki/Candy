/*****************************************************************//**
 * \file   Font.cpp
 * \brief  フォント
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Font.h"

CANDY_APP_NAMESPACE_BEGIN

namespace Font
{
	struct UvHeader
	{
		u32 m_NumCodes;
	};

	struct UvInfoRaw
	{
		u32 m_Code;
		f32 x0, y0, x1, y1;
	};
	struct UvInfo
	{
		Rect m_Rect;
	};

	struct FontData
	{
		std::map<u32, UvInfo> m_Uvs;
		graphic::Buffer m_TextureBuffer;
	};
	std::vector<FontData> m_FontDatas;

	// フォントの読み込み
	void LoadFont(const std::string& _fontName);
}

// 初期化
void Font::Startup()
{
	for (auto fontName : FontFileNames)LoadFont(fontName);
}

// 破棄
void Font::Cleanup()
{
	m_FontDatas.clear();
}

// フォントテクスチャバッファの取得
graphic::Buffer& Font::GetFontTextureBuffer(const FONT_TYPE _fontType)
{
	return m_FontDatas[(s32)_fontType].m_TextureBuffer;
}

// フォントのUVの取得
Rect Font::GetFontUv(const FONT_TYPE _fontType, const u32 _c)
{
	if (!m_FontDatas[(s32)_fontType].m_Uvs.contains(_c))
	{
		CANDY_LOG("UVがありません[{0}]", _c);
		return m_FontDatas[(s32)_fontType].m_Uvs['?'].m_Rect;
	}
	return m_FontDatas[(s32)_fontType].m_Uvs[_c].m_Rect;
}

// フォントの読み込み
void Font::LoadFont(const std::string& _fontName)
{
	const std::string binPath = core::Config::GetDataPath() + std::string{ R"(\Font\)"} + _fontName + ".bin";
	const std::string texturePath = core::Config::GetDataPath() + std::string{ R"(\Font\)" } + _fontName + ".dds";

	auto binBufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
	auto textureBufferInfo = std::make_shared<core::FileSystem::BufferInfo>();

	if (!core::FileSystem::RequestReadNoWait(binPath, binBufferInfo))
	{
		CANDY_LOG_ERR("フォントのバイナリファイル読み込みに失敗");
		return;
	}
	if (!core::FileSystem::RequestReadNoWait(texturePath, textureBufferInfo))
	{
		CANDY_LOG_ERR("フォントのバイナリファイル読み込みに失敗");
		return;
	}

	FontData fontData;

	u32 binOffset = 0;
	const UvHeader& uvHeader = *(UvHeader*)(binBufferInfo->m_Buffer.get() + binOffset);
	binOffset += sizeof(UvHeader);
	for (u32 i = 0; i < uvHeader.m_NumCodes; ++i)
	{
		const UvInfoRaw& uvInfo = *(UvInfoRaw*)(binBufferInfo->m_Buffer.get() + binOffset);
		binOffset += sizeof(UvInfoRaw);

		fontData.m_Uvs[uvInfo.m_Code].m_Rect.setPos(uvInfo.x0, uvInfo.y0, uvInfo.x1, uvInfo.y1);
	}

	graphic::BufferStartupInfo textureBufferStartupInfo;
	textureBufferStartupInfo.setTextureStartupInfo(graphic::types::GRAPHIC_FORMAT::BC3_UNORM, 4096, 4096);
	fontData.m_TextureBuffer.startup(graphic::System::GetDevice(), textureBufferStartupInfo);
	std::byte* ddsBuf = graphic::Texture::DDS::ReadAlloc(textureBufferInfo->m_Buffer.get(), textureBufferInfo->m_BufferSize);
	graphic::TextureUploder::CreateTexture(fontData.m_TextureBuffer, ddsBuf, 4096 * 4096);
	delete ddsBuf;

	m_FontDatas.push_back(fontData);
}

CANDY_APP_NAMESPACE_END
