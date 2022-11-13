/*****************************************************************//**
 * \file   ModelType.h
 * \brief  モデルのタイプ
 * \author Yu Ishiyama.
 * \date   2022/11/07
 *********************************************************************/

#ifndef CANDY_APP_MODEL_TYPE_H
#define CANDY_APP_MODEL_TYPE_H

#include <App/AppInclude.h>

CANDY_APP_NAMESPACE_BEGIN

struct ModelVertexInfo
{
	Vec4 m_Position;
	Vec4 m_Normal;
	Vec4 m_TexCoord0;
	Vec4 m_TexCoord1;
};

using ModelIndexType = u32;
inline constexpr graphic::types::GRAPHIC_FORMAT ModelIndexGraphicFormat = graphic::types::GRAPHIC_FORMAT::R32_UINT;

CANDY_APP_NAMESPACE_END

#endif // CANDY_APP_MODEL_TYPE_H
