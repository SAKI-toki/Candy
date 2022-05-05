#include "Shader.h"
#include "Vertex/VertexShader.h"
#include "Pixel/PixelShader.h"

CANDY_NAMESPACE_BEGIN

namespace Shader
{
	std::vector<VertexShader> m_VertexShaders;
	std::vector<PixelShader> m_PixelShaders;
}

void Shader::Startup()
{
	//FileSystem::RequestReadNoWait();
}

void Shader::Cleanup()
{
	for (auto& vertexShader : m_VertexShaders)vertexShader.cleanup();
	for (auto& pixelShader : m_PixelShaders)pixelShader.cleanup();
	m_VertexShaders.clear();
	m_PixelShaders.clear();
}

CANDY_NAMESPACE_END
