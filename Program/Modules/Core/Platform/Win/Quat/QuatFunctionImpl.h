/*****************************************************************//**
 * \file   QuatFunctionImpl.h
 * \brief  Quaternion関連の関数の実装部(Win)
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_QUAT_FUNCTION_IMPL_H
#define CANDY_CORE_QUAT_FUNCTION_IMPL_H

#include <Core/CoreInclude.h>

CANDY_CORE_NAMESPACE_BEGIN

vector_type QuatSetImpl(const f32 _x, const f32 _y, const f32 _z, const f32 _w);
vector_type QuatSetIdentityImpl();

vector_type QuatMulImpl(const vector_type _q1, const vector_type _q2);

vector_type AngleToQuatImpl(const vector_type _angle);

vector_type QuatSlerpImpl(const vector_type _q1, const vector_type _q2, const f32 _time);

CANDY_CORE_NAMESPACE_END

#endif // CANDY_CORE_QUAT_FUNCTION_IMPL_H
