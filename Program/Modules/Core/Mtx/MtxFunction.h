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

#if PLATFORM_WIN
#include <Core/Platform/Win/Mtx/MtxFunctionImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

void MtxSet(Mtx& _out, const Vec4& _v1, const Vec4& _v2, const Vec4& _v3, const Vec4& _v4);
void MtxSetIdentity(Mtx& _out);

void MtxMul(Mtx& _out, const Mtx& _m1, const Mtx& _m2);

void MtxTranspose(Mtx& _out, const Mtx& _m);

void MtxTranslation(Mtx& _out, const Vec4& _v);
void MtxRotationZXY(Mtx& _out, const Vec4& _v);
void MtxScaling(Mtx& _out, const Vec4& _v);

void MtxOrthographic(Mtx& _out, const f32 _width, const f32 _height, const f32 _near, const f32 _far);
void MtxLookAt(Mtx& _out, const Vec4& _view, const Vec4& _lookAt, const Vec4& _up);

CANDY_NAMESPACE_END

#endif // CANDY_CORE_MTX_FUNCTION_H
