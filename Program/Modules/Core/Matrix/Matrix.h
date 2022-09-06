/*****************************************************************//**
 * \file   Matrix.h
 * \brief  Matrix
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_MATRIX_H
#define CANDY_CORE_MATRIX_H

#include <Core/CoreInclude.h>

#if PLATFORM_WIN
#include <Core/Platform/Win/Matrix/MatrixImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

struct Matrix : core::MatrixImpl
{
	Matrix();

	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);
	Matrix(Matrix&&)noexcept;
	Matrix& operator=(Matrix&&)noexcept;

	void setIdentity();
};

CANDY_NAMESPACE_END

#endif // CANDY_CORE_MATRIX_H
