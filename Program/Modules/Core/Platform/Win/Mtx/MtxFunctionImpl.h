/*****************************************************************//**
 * \file   MatrixFunctionImpl.h
 * \brief  Matrix関連の関数の実装部
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_MATRIX_FUNCTION_IMPL_H
#define CANDY_CORE_MATRIX_FUNCTION_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

void MtxSetImpl(vector_type (&_out)[4], const vector_type _v1, const vector_type _v2, const vector_type _v3, const vector_type _v4);
void MtxSetIdentityImpl(vector_type (&_out)[4]);

void MtxTransposeImpl(vector_type (&_out)[4], const vector_type (&_m)[4]);

void MtxTransformationImpl(vector_type (&_out)[4], const vector_type _pos, const vector_type _rot, const vector_type _scale);
void MtxTranslationImpl(vector_type (&_out)[4], const vector_type _v);
void MtxRotationZYXImpl(vector_type (&_out)[4], const vector_type _v);
void MtxScalingImpl(vector_type (&_out)[4], const vector_type _v);

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MATRIX_FUNCTION_IMPL_H
