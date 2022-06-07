#include "GraphicResourceManager.h"
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/Pipeline/GraphicPipeline.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>
#include <Graphic/Graphic.h>

CANDY_NAMESPACE_BEGIN

namespace Graphic
{
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
		m_RegistBufferLists.resize(Graphic::GetBackBufferCount());
		m_RegistRootSignatureLists.resize(Graphic::GetBackBufferCount());
		m_RegistPipelineLists.resize(Graphic::GetBackBufferCount());
		m_RegistDescriptorLists.resize(Graphic::GetBackBufferCount());
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
		m_RegistBufferLists[Graphic::GetBackBufferIndex()].push_back(_buffer);
	}
	void ResourceManager::Regist(const RootSignature& _rootSignature)
	{
		m_RegistRootSignatureLists[Graphic::GetBackBufferIndex()].push_back(_rootSignature);
	}
	void ResourceManager::Regist(const Pipeline& _pipeline)
	{
		m_RegistPipelineLists[Graphic::GetBackBufferIndex()].push_back(_pipeline);
	}
	void ResourceManager::Regist(const Descriptor& _descriptor)
	{
		m_RegistDescriptorLists[Graphic::GetBackBufferIndex()].push_back(_descriptor);
	}

}

CANDY_NAMESPACE_END
