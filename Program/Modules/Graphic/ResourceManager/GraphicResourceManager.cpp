#include "GraphicResourceManager.h"
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/Pipeline/GraphicPipeline.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>
#include <Graphic/System/GraphicSystem.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace ResourceManager
{
	template<typename T>
	using RegistListType = std::vector<std::vector<T>>;
	RegistListType<Buffer> m_RegistBufferLists;
	RegistListType<RootSignature> m_RegistRootSignatureLists;
	RegistListType<Pipeline> m_RegistPipelineLists;
	RegistListType<Descriptor> m_RegistDescriptorLists;
}

void ResourceManager::Startup()
{
	m_RegistBufferLists.resize(Config::GetBackBufferCount());
	m_RegistRootSignatureLists.resize(Config::GetBackBufferCount());
	m_RegistPipelineLists.resize(Config::GetBackBufferCount());
	m_RegistDescriptorLists.resize(Config::GetBackBufferCount());
}

void ResourceManager::Cleanup()
{
	m_RegistBufferLists.clear();
	m_RegistRootSignatureLists.clear();
	m_RegistPipelineLists.clear();
	m_RegistDescriptorLists.clear();
}

void ResourceManager::Flip(const s32 _prevBackBufferIndex, const s32 _nextBackBufferIndex)
{
	CANDY_UNUSED_VALUE(_prevBackBufferIndex);

	m_RegistBufferLists[_nextBackBufferIndex].clear();
	m_RegistRootSignatureLists[_nextBackBufferIndex].clear();
	m_RegistPipelineLists[_nextBackBufferIndex].clear();
	m_RegistDescriptorLists[_nextBackBufferIndex].clear();
}

void ResourceManager::Regist(const Buffer& _buffer)
{
	m_RegistBufferLists[System::GetBackBufferIndex()].push_back(_buffer);
}
void ResourceManager::Regist(const RootSignature& _rootSignature)
{
	m_RegistRootSignatureLists[System::GetBackBufferIndex()].push_back(_rootSignature);
}
void ResourceManager::Regist(const Pipeline& _pipeline)
{
	m_RegistPipelineLists[System::GetBackBufferIndex()].push_back(_pipeline);
}
void ResourceManager::Regist(const Descriptor& _descriptor)
{
	m_RegistDescriptorLists[System::GetBackBufferIndex()].push_back(_descriptor);
}

CANDY_GRAPHIC_NAMESPACE_END
