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
	std::map<u32, TextureInfo> m_TextureInfoMap;
	TextureInfo m_DummyTextureInfo;
}

void TextureResourceManager::Startup()
{
	auto& graphicDevice = graphic::System::GetDevice();

	auto path = std::string{ core::Config::GetDataPath() } + "Texture\\Dummy.dds";
	auto bufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
	CANDY_ASSERT(core::FileSystem::RequestReadNoWait(path, bufferInfo));

	auto textureBin = graphic::Texture::DDS::ReadAlloc(bufferInfo->m_Buffer, bufferInfo->m_BufferSize);
	CANDY_ASSERT(textureBin);
	graphic::BufferStartupInfo dummyTextureBufferStartupInfo;
	dummyTextureBufferStartupInfo.setTextureStartupInfo(textureBin->m_Format, textureBin->m_Width, textureBin->m_Height, textureBin->m_MipMapCount);
	m_DummyTextureInfo.m_Buffer.startup(graphicDevice, dummyTextureBufferStartupInfo);
	graphic::TextureUploder::CreateTexture(m_DummyTextureInfo.m_Buffer, textureBin->m_Buffer.get(), textureBin->m_BufferSize, textureBin->m_MipMapCount);

	m_DummyTextureInfo.m_Format = textureBin->m_Format;
	m_DummyTextureInfo.m_Width = textureBin->m_Width;
	m_DummyTextureInfo.m_Height = textureBin->m_Height;
	m_DummyTextureInfo.m_MipMapCount = textureBin->m_MipMapCount;
}

void TextureResourceManager::Cleanup()
{

}

void TextureResourceManager::Add(const std::string_view _path, const TextureInfo& _info)
{
	const u32 hash = core::Fnv::Hash32(core::Path::FormatPath(_path));
	m_TextureInfoMap.insert({ hash, _info });
}

void TextureResourceManager::Remove(const std::string_view _path)
{
	const u32 hash = core::Fnv::Hash32(core::Path::FormatPath(_path));
	m_TextureInfoMap.erase(hash);
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

CANDY_APP_NAMESPACE_END
