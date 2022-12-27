/*****************************************************************//**
 * \file   TextureResourceManager.cpp
 * \brief  テクスチャリソースの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "TextureResourceManager.h"

CANDY_APP_NAMESPACE_BEGIN

namespace TextureResourceManager
{
	bool CreateTextureInfo(TextureInfo& _outTextureInfo, const std::shared_ptr<core::FileSystem::BufferInfo> _bufferInfo);

	std::map<u32, TextureInfo> m_TextureInfoMap;
	TextureInfo m_DummyTextureInfo;
}

void TextureResourceManager::Startup()
{
	auto path = std::string{ core::Config::GetDataPath() } + "Texture\\CesiumMan_img0.dds";
	auto bufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
	CANDY_ASSERT(core::FileSystem::RequestReadNoWait(path, bufferInfo));
	CreateTextureInfo(m_DummyTextureInfo, bufferInfo);
}

void TextureResourceManager::Cleanup()
{
	for (auto [hash, textureInfo] : m_TextureInfoMap)
	{
		textureInfo.clear();
	}
	m_TextureInfoMap.clear();

	m_DummyTextureInfo.clear();
}

void TextureResourceManager::Add(const std::string_view _path, const std::shared_ptr<core::FileSystem::BufferInfo> _bufferInfo)
{
	TextureInfo textureInfo;
	if (!CreateTextureInfo(textureInfo, _bufferInfo))
	{
		CANDY_LOG_ERR("テクスチャの読み込みに失敗[{0}]", _path);
		return;
	}
	m_TextureInfoMap.insert({ core::Fnv::Hash32(core::Path::FormatPath(_path)), textureInfo });
}

void TextureResourceManager::Remove(const std::string_view _path)
{
	m_TextureInfoMap.erase(core::Fnv::Hash32(core::Path::FormatPath(_path)));
}

const TextureResourceManager::TextureInfo& TextureResourceManager::GetTextureInfo(const std::string_view _path)
{
	return GetTextureInfo(core::Fnv::Hash32(core::Path::FormatPath(_path)));
}

const TextureResourceManager::TextureInfo& TextureResourceManager::GetTextureInfo(const u32 _hash)
{
	auto itr = m_TextureInfoMap.find(_hash);
	if (itr == m_TextureInfoMap.end())
	{
		CANDY_LOG("テクスチャが見つからなかったのでdummyテクスチャを返します");
		return m_DummyTextureInfo;
	}
	return itr->second;
}

const TextureResourceManager::TextureInfo& TextureResourceManager::GetDummyTextureInfo()
{
	return m_DummyTextureInfo;
}

bool TextureResourceManager::CreateTextureInfo(TextureInfo& _outTextureInfo, const std::shared_ptr<core::FileSystem::BufferInfo> _bufferInfo)
{
	_outTextureInfo.clear();

	auto& graphicDevice = graphic::System::GetDevice();

	auto textureBin = graphic::Texture::DDS::ReadAlloc(_bufferInfo->m_Buffer, _bufferInfo->m_BufferSize);
	if (!textureBin)return false;
	
	graphic::BufferStartupInfo dummyTextureBufferStartupInfo;
	dummyTextureBufferStartupInfo.setTextureStartupInfo(textureBin->m_Format, textureBin->m_Width, textureBin->m_Height, textureBin->m_MipMapCount);
	_outTextureInfo.m_Buffer.startup(graphicDevice, dummyTextureBufferStartupInfo);
	graphic::TextureUploder::CreateTexture(_outTextureInfo.m_Buffer, textureBin->m_Buffer.get(), textureBin->m_BufferSize, textureBin->m_MipMapCount);

	_outTextureInfo.m_Format = textureBin->m_Format;
	_outTextureInfo.m_Width = textureBin->m_Width;
	_outTextureInfo.m_Height = textureBin->m_Height;
	_outTextureInfo.m_MipMapCount = textureBin->m_MipMapCount;

	return true;
}

CANDY_APP_NAMESPACE_END
