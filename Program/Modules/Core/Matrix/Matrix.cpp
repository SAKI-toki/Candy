/*****************************************************************//**
 * \file   Matrix.cpp
 * \brief  Matrix
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "Matrix.h"

CANDY_NAMESPACE_BEGIN

void Matrix::setIdentity()
{
	v[0] = Vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
	v[1] = Vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
	v[2] = Vec4{ 0.0f, 0.0f, 1.0f, 0.0f };
	v[3] = Vec4{ 0.0f, 0.0f, 0.0f, 1.0f };
}

CANDY_NAMESPACE_END
