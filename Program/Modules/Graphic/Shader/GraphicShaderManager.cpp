/*****************************************************************//**
 * \file   GraphicShader.cpp
 * \brief  シェーダー
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "GraphicShaderManager.h"
#include <Core/FileSystem/FileSystem.h>

CANDY_GRAPHIC_NAMESPACE_BEGIN

namespace ShaderManager
{
	std::vector<std::unique_ptr<std::byte[]>> m_ShaderBuffers;
	std::vector<VertexShader> m_VertexShaders;
	std::vector<PixelShader> m_PixelShaders;
}

// 初期化
void ShaderManager::Startup()
{
	std::string baseShaderPath = core::Config::GetDataPath() + std::string{ R"(Shader\)" };

	for (auto shaderFileName : ShaderFileNames)
	{
		{
			std::string filePath = baseShaderPath + shaderFileName + ".vso";
			auto bufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
			core::FileSystem::RequestReadNoWait(filePath, bufferInfo);
			VertexShader vs;
			vs.startup(bufferInfo->m_Buffer.get(), bufferInfo->m_BufferSize);
			m_ShaderBuffers.push_back(std::move(bufferInfo->m_Buffer));
			m_VertexShaders.push_back(vs);
		}

		{
			std::string filePath = baseShaderPath + shaderFileName + ".pso";
			auto bufferInfo = std::make_shared<core::FileSystem::BufferInfo>();
			core::FileSystem::RequestReadNoWait(filePath, bufferInfo);
			PixelShader ps;
			ps.startup(bufferInfo->m_Buffer.get(), bufferInfo->m_BufferSize);
			m_ShaderBuffers.push_back(std::move(bufferInfo->m_Buffer));
			m_PixelShaders.push_back(ps);
		}
	}
}

// 破棄
void ShaderManager::Cleanup()
{
	for (auto& vertexShader : m_VertexShaders)vertexShader.cleanup();
	for (auto& pixelShader : m_PixelShaders)pixelShader.cleanup();
	m_VertexShaders.clear();
	m_PixelShaders.clear();
	m_ShaderBuffers.clear();
}

// バーテックスシェーダーの取得
const VertexShader& ShaderManager::GetVertexShader(const SHADER_TYPE _shaderType)
{
	return m_VertexShaders[static_cast<s32>(_shaderType)];
}

// ピクセルシェーダーの取得
const PixelShader& ShaderManager::GetPixelShader(const SHADER_TYPE _shaderType)
{
	return m_PixelShaders[static_cast<s32>(_shaderType)];
}

CANDY_GRAPHIC_NAMESPACE_END
