/*****************************************************************//**
 * \file   TextureResourceManager.h
 * \brief  テクスチャリソースの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_TEXTURE_RESOURCE_MANAGER_H
#define CANDY_APP_TEXTURE_RESOURCE_MANAGER_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace TextureResourceManager
{
	struct TextureInfo
	{
		graphic::Buffer m_Buffer;
		u32 m_Width{};
		u32 m_Height{};
		graphic::types::GRAPHIC_FORMAT m_Format{};
		s32 m_MipMapCount{};
		void clear() { m_Buffer.cleanup(); }
	};

	void Startup();
	void Cleanup();

	void Add(const std::string_view _path, const std::shared_ptr<core::FileSystem::BufferInfo> _bufferInfo);
	void Remove(const std::string_view _path);

	const TextureInfo& GetTextureInfo(const std::string_view _path);
	const TextureInfo& GetTextureInfo(const u32 _hash);

	const TextureInfo& GetDummyTextureInfo();
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_TEXTURE_RESOURCE_MANAGER_H
