#ifndef CANDY_TEXTURE_READ_DDS_H
#define CANDY_TEXTURE_READ_DDS_H

CANDY_NAMESPACE_BEGIN

namespace Texture::DDS
{
	std::byte* ReadAlloc(const std::byte* const _bytes, const u64 _byteSize);
}

CANDY_NAMESPACE_END

#endif // CANDY_TEXTURE_READ_DDS_H
