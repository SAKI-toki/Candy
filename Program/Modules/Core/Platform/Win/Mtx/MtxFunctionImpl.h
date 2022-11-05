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

void MtxMulImpl(vector_type(&_out)[4], const vector_type(&_m1)[4], const vector_type(&_m2)[4]);

void MtxTransposeImpl(vector_type (&_out)[4], const vector_type (&_m)[4]);

void MtxTranslationImpl(vector_type (&_out)[4], const vector_type _v);
void MtxRotationZXYImpl(vector_type (&_out)[4], const vector_type _v);
void MtxScalingImpl(vector_type (&_out)[4], const vector_type _v);

void MtxOrthographicImpl(vector_type(&_out)[4], const f32 _width, const f32 _height, const f32 _near, const f32 _far);
void MtxPerspectiveImpl(vector_type(&_out)[4], const f32 _fov, const f32 _aspectRatio, const f32 _near, const f32 _far);
void MtxLookToImpl(vector_type(&_out)[4], const vector_type _view, const vector_type _lookDir, const vector_type _up);

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_MATRIX_FUNCTION_IMPL_H
