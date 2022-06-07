/*****************************************************************//**
 * \file   __ShaderCpp.cpp
 * \brief  シェーダー関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Shader.cpp"
#include "Base/BaseShader.cpp"
#include "Vertex/VertexShader.cpp"
#include "Pixel/PixelShader.cpp"

#if PLATFORM_WIN
#include "Platform/Win/Base/BaseShaderImpl.cpp"
#endif // PLATFORM_WIN
