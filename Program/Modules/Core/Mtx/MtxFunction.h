/*****************************************************************//**
 * \file   MtxFunction.h
 * \brief  Matrix関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_MTX_FUNCTION_H
#define CANDY_CORE_MTX_FUNCTION_H

#include <Core/CoreInclude.h>
#include "Mtx.h"

CANDY_NAMESPACE_BEGIN

Mtx MtxSet(const Vec4& _v1, const Vec4& _v2, const Vec4& _v3, const Vec4& _v4);
Mtx MtxSetIdentity();

Mtx MtxMul(const Mtx& _m1, const Mtx& _m2);

Mtx MtxTranspose(const Mtx& _m);

Mtx MtxTranslation(const Vec4& _v);
Mtx MtxRotation(const Vec4& _v, const ROTATION_ORDER _rotationOrder = ROTATION_ORDER::DEFAULT);
Mtx MtxRotationZXY(const Vec4& _v);
Mtx MtxRotationZYX(const Vec4& _v);
Mtx MtxRotationQuat(const Quat& _q);
Mtx MtxScaling(const Vec4& _v);

Mtx MtxOrthographic(const f32 _width, const f32 _height, const f32 _near, const f32 _far);
Mtx MtxPerspective(const f32 _fov, const f32 _aspectRatio, const f32 _near, const f32 _far);
Mtx MtxLookAt(const Vec4& _view, const Vec4& _lookAt, const Vec4& _up);
Mtx MtxLookTo(const Vec4& _view, const Vec4& _lookDir, const Vec4& _up);

CANDY_NAMESPACE_END

#endif // CANDY_CORE_MTX_FUNCTION_H
