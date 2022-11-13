#include "GraphicResourceLifetime.h"
#include <Graphic/Buffer/GraphicBuffer.h>
#include <Graphic/RootSignature/GraphicRootSignature.h>
#include <Graphic/Pipeline/GraphicPipeline.h>
#include <Graphic/Descriptor/GraphicDescriptor.h>
#include <Graphic/System/GraphicSystem.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace ResourceLifetime
{
	template<typename T>
	using RegistListType = std::vector<std::vector<T>>;
	RegistListType<Buffer> m_RegistBufferLists;
	RegistListType<RootSignature> m_RegistRootSignatureLists;
	RegistListType<Pipeline> m_RegistPipelineLists;
	RegistListType<Descriptor> m_RegistDescriptorLists;

	core::CriticalSection m_CriticalSection;
}

void ResourceLifetime::Startup()
{
	m_CriticalSection.startup();

	m_RegistBufferLists.resize(Config::GetBackBufferCount());
	m_RegistRootSignatureLists.resize(Config::GetBackBufferCount());
	m_RegistPipelineLists.resize(Config::GetBackBufferCount());
	m_RegistDescriptorLists.resize(Config::GetBackBufferCount());
}

void ResourceLifetime::Cleanup()
{
	m_RegistBufferLists.clear();
	m_RegistRootSignatureLists.clear();
	m_RegistPipelineLists.clear();
	m_RegistDescriptorLists.clear();

	m_CriticalSection.cleanup();
}

void ResourceLifetime::Flip(const s32 _prevBackBufferIndex, const s32 _nextBackBufferIndex)
{
	CANDY_UNUSED_VALUE(_prevBackBufferIndex);

	m_RegistBufferLists[_nextBackBufferIndex].clear();
	m_RegistRootSignatureLists[_nextBackBufferIndex].clear();
	m_RegistPipelineLists[_nextBackBufferIndex].clear();
	m_RegistDescriptorLists[_nextBackBufferIndex].clear();
}

void ResourceLifetime::Regist(const Buffer& _buffer)
{
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	m_RegistBufferLists[System::GetBackBufferIndex()].push_back(_buffer);
}
void ResourceLifetime::Regist(const RootSignature& _rootSignature)
{
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	m_RegistRootSignatureLists[System::GetBackBufferIndex()].push_back(_rootSignature);
}
void ResourceLifetime::Regist(const Pipeline& _pipeline)
{
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	m_RegistPipelineLists[System::GetBackBufferIndex()].push_back(_pipeline);
}
void ResourceLifetime::Regist(const Descriptor& _descriptor)
{
	CANDY_CRITICAL_SECTION_SCOPE(m_CriticalSection);
	m_RegistDescriptorLists[System::GetBackBufferIndex()].push_back(_descriptor);
}

CANDY_GRAPHIC_NAMESPACE_END
