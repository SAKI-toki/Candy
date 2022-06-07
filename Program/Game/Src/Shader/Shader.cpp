/*****************************************************************//**
 * \file   Shader.cpp
 * \brief  シェーダー
 * \author Yu Ishiyama.
 * \date   2022/06/03
 *********************************************************************/

#include "Shader.h"
#include <FileSystem/FileSystem.h>

CANDY_NAMESPACE_BEGIN

namespace Shader
{
	std::vector<std::byte*> m_ShaderBuffers;
	std::vector<VertexShader> m_VertexShaders;
	std::vector<PixelShader> m_PixelShaders;
}

// 初期化
void Shader::Startup()
{
	std::string baseShaderPath = Setting::GetDataPath() + std::string{ R"(Shader\)" };

	for (auto shaderFileName : ShaderFileNames)
	{
		{
			std::string filePath = baseShaderPath + shaderFileName + ".vso";
			u64 fileSize = FileSystem::GetFileSize(filePath);
			std::byte* buf = new std::byte[fileSize];
			FileSystem::RequestReadNoWait(filePath, buf, fileSize);
			m_ShaderBuffers.push_back(buf);
			VertexShader vs;
			vs.startup(buf, fileSize);
			m_VertexShaders.push_back(vs);
		}

		{
			std::string filePath = baseShaderPath + shaderFileName + ".pso";
			u64 fileSize = FileSystem::GetFileSize(filePath);
			std::byte* buf = new std::byte[fileSize];
			FileSystem::RequestReadNoWait(filePath, buf, fileSize);
			m_ShaderBuffers.push_back(buf);
			PixelShader ps;
			ps.startup(buf, fileSize);
			m_PixelShaders.push_back(ps);
		}
	}
}

// 破棄
void Shader::Cleanup()
{
	for (auto& vertexShader : m_VertexShaders)vertexShader.cleanup();
	for (auto& pixelShader : m_PixelShaders)pixelShader.cleanup();
	m_VertexShaders.clear();
	m_PixelShaders.clear();
	for (auto& shaderBuffer : m_ShaderBuffers)delete[] shaderBuffer;
	m_ShaderBuffers.clear();
}

// バーテックスシェーダーの取得
const Shader::VertexShader& Shader::GetVertexShader(const SHADER_TYPE _shaderType)
{
	return m_VertexShaders[static_cast<s32>(_shaderType)];
}

// ピクセルシェーダーの取得
const Shader::PixelShader& Shader::GetPixelShader(const SHADER_TYPE _shaderType)
{
	return m_PixelShaders[static_cast<s32>(_shaderType)];
}

CANDY_NAMESPACE_END
