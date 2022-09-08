/*****************************************************************//**
 * \file   TextureManager.h
 * \brief  テクスチャの管理
 * \author Yu Ishiyama.
 * \date   2022/07/19
 *********************************************************************/

#ifndef CANDY_APP_TEXTURE_MANAGER_H
#define CANDY_APP_TEXTURE_MANAGER_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

namespace TextureManager
{
	struct TextureInfo
	{
		graphic::Buffer m_Buffer;
		f32 m_Width{};
		f32 m_Height{};
		graphic::types::GRAPHIC_FORMAT m_Format{};
	};

	void Startup();
	void Cleanup();

	void Add(const std::string_view _path, const TextureInfo& _info);
	void Remove(const std::string_view _path);

	const TextureInfo& GetTextureInfo(const std::string_view _path);
	const TextureInfo& GetTextureInfo(const u32 _hash);

	const TextureInfo& GetDummyTextureInfo();
}

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_TEXTURE_MANAGER_H
