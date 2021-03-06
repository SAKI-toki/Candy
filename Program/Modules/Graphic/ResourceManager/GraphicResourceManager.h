#ifndef CANDY_GRAPHIC_RESOURCE_MANAGER_H
#define CANDY_GRAPHIC_RESOURCE_MANAGER_H

#include <Graphic/GraphicInclude.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

class Buffer;
class RootSignature;
class Pipeline;
class Descriptor;

namespace ResourceManager
{
	void Startup();
	void Cleanup();

	void Flip(const s32 _prevBackBufferIndex, const s32 _nextBackBufferIndex);

	void Regist(const Buffer& _buffer);
	void Regist(const RootSignature& _rootSignature);
	void Regist(const Pipeline& _pipeline);
	void Regist(const Descriptor& _descriptor);
}

CANDY_GRAPHIC_NAMESPACE_END

#endif // CANDY_GRAPHIC_RESOURCE_MANAGER_H
