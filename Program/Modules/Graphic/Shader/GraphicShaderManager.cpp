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
	std::vector<std::byte*> m_ShaderBuffers;
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
			u64 fileSize = core::FileSystem::GetFileSize(filePath);
			std::byte* buf = new std::byte[fileSize];
			core::FileSystem::RequestReadNoWait(filePath, buf, fileSize);
			m_ShaderBuffers.push_back(buf);
			VertexShader vs;
			vs.startup(buf, fileSize);
			m_VertexShaders.push_back(vs);
		}

		{
			std::string filePath = baseShaderPath + shaderFileName + ".pso";
			u64 fileSize = core::FileSystem::GetFileSize(filePath);
			std::byte* buf = new std::byte[fileSize];
			core::FileSystem::RequestReadNoWait(filePath, buf, fileSize);
			m_ShaderBuffers.push_back(buf);
			PixelShader ps;
			ps.startup(buf, fileSize);
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
	for (auto& shaderBuffer : m_ShaderBuffers)delete[] shaderBuffer;
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
