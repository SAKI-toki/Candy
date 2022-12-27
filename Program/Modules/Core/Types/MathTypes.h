/*****************************************************************//**
 * \file   MathTypes.h
 * \brief  数学関連のタイプ
 * \author Yu Ishiyama.
 * \date   2022/06/08
 *********************************************************************/

#ifndef CANDY_CORE_MATH_TYPES_H
#define CANDY_CORE_MATH_TYPES_H

#include <Core/CoreInclude.h>

CANDY_NAMESPACE_BEGIN

enum class ROTATION_ORDER
{
	XYZ,
	XZY,
	YXZ,
	YZX,
	ZXY,
	ZYX,
	DEFAULT = ZYX,
};

CANDY_NAMESPACE_END

#endif // CANDY_CORE_MATH_TYPES_H
