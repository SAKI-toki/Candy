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
	void Startup();
	void Cleanup();

	void ExecuteUploadTexture(const Graphic::CommandQueue& _commandQueue);
	void PostDraw();

	void CreateTexture(Graphic::Buffer& _buffer, const std::byte* const _pixels, const u64 _size);
}

CANDY_NAMESPACE_END

#endif // CANDY_TEXTURE_H
