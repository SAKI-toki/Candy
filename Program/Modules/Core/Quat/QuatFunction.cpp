/*****************************************************************//**
 * \file   QuatFunction.cpp
 * \brief  Quaternion関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "QuatFunction.h"

#if PLATFORM_WIN
#include <Core/Platform/Win/Quat/QuatFunctionImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

Quat QuatSet(const f32 _x, const f32 _y, const f32 _z, const f32 _w)
{
	return core::QuatSetImpl(_x, _y, _z, _w);
}

Quat QuatSetIdentity()
{
	return core::QuatSetIdentityImpl();
}

Quat QuatMul(const Quat& _q1, const Quat& _q2)
{
	return core::QuatMulImpl(_q1.vector, _q2.vector);
}

Quat AngleToQuat(const Vec4& _angle)
{
	return core::AngleToQuatImpl(_angle.vector);
}

Quat QuatSlerp(const Quat& _q1, const Quat& _q2, const f32 _time)
{
	return core::QuatSlerpImpl(_q1.vector, _q2.vector, _time);
}

CANDY_NAMESPACE_END
