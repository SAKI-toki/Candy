/*****************************************************************//**
 * \file   QuatFunction.h
 * \brief  Quaternion関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#ifndef CANDY_CORE_QUAT_FUNCTION_H
#define CANDY_CORE_QUAT_FUNCTION_H

#include <Core/CoreInclude.h>
#include "Quat.h"

CANDY_NAMESPACE_BEGIN

Quat QuatSet(const f32 _x, const f32 _y, const f32 _z, const f32 _w);
Quat QuatSetIdentity();

Quat QuatMul(const Quat& _q1, const Quat& _q2);

Quat AngleToQuat(const Vec4& _angle);

Quat QuatSlerp(const Quat& _q1, const Quat& _q2, const f32 _time);

CANDY_NAMESPACE_END

#endif // CANDY_CORE_QUAT_FUNCTION_H
