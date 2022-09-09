/*****************************************************************//**
 * \file   TextureManager.cpp
 * \brief  テクスチャの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#include "TextureManager.h"

CANDY_APP_NAMESPACE_BEGIN

namespace TextureManager
{
	std::map<u32, TextureInfo> m_TextureInfoMap;
	TextureInfo m_DummyTextureInfo;
}

void TextureManager::Startup()
{
	auto& graphicDevice = graphic::System::GetDevice();

	auto path = std::string{ core::Config::GetDataPath() } + "Texture\\Dummy.dds";
	auto bufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
	core::FileSystem::RequestReadNoWait(path, bufferInfo);

	auto result = graphic::Texture::DDS::ReadAlloc(bufferInfo->m_Buffer, bufferInfo->m_BufferSize);
	graphic::BufferStartupInfo dummyTextureBufferStartupInfo;
	dummyTextureBufferStartupInfo.setTextureStartupInfo(graphic::types::GRAPHIC_FORMAT::BC3_UNORM, 1024, 1024);
	m_DummyTextureInfo.m_Buffer.startup(graphicDevice, dummyTextureBufferStartupInfo);
	graphic::TextureUploder::CreateTexture(m_DummyTextureInfo.m_Buffer, result.get(), 1024 * 1024);

	m_DummyTextureInfo.m_Format = graphic::types::GRAPHIC_FORMAT::BC3_UNORM;
	m_DummyTextureInfo.m_Width = 1024;
	m_DummyTextureInfo.m_Height = 1024;
}

void TextureManager::Cleanup()
{

}

void TextureManager::Add(const std::string_view _path, const TextureInfo& _info)
{
	const u32 hash = core::Fnv::Hash32(core::Path::FormatPath(_path));
	m_TextureInfoMap.insert({ hash, _info });
}

void TextureManager::Remove(const std::string_view _path)
{
	const u32 hash = core::Fnv::Hash32(core::Path::FormatPath(_path));
	m_TextureInfoMap.erase(hash);
}

const TextureManager::TextureInfo& TextureManager::GetTextureInfo(const std::string_view _path)
{
	return GetTextureInfo(core::Fnv::Hash32(core::Path::FormatPath(_path)));
}

const TextureManager::TextureInfo& TextureManager::GetTextureInfo(const u32 _hash)
{
	auto itr = m_TextureInfoMap.find(_hash);
	if (itr == m_TextureInfoMap.end())
	{
		CANDY_LOG("テクスチャが見つからなかったのでdummyテクスチャを返します");
		return m_DummyTextureInfo;
	}
	return itr->second;
}

const TextureManager::TextureInfo& TextureManager::GetDummyTextureInfo()
{
	return m_DummyTextureInfo;
}

CANDY_APP_NAMESPACE_END
