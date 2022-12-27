/*****************************************************************//**
 * \file   MtxFunction.cpp
 * \brief  Matrix関連の関数
 * \author Yu Ishiyama.
 * \date   2022/07/09
 *********************************************************************/

#include "MtxFunction.h"

#if PLATFORM_WIN
#include <Core/Platform/Win/Mtx/MtxFunctionImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

Mtx MtxSet(const Vec4& _v1, const Vec4& _v2, const Vec4& _v3, const Vec4& _v4)
{
	Mtx outMtx;
	core::MtxSetImpl(outMtx.vector, _v1.vector, _v2.vector, _v3.vector, _v4.vector);
	return outMtx;
}

Mtx MtxSetIdentity()
{
	Mtx outMtx;
	core::MtxSetIdentityImpl(outMtx.vector);
	return outMtx;
}

Mtx MtxMul(const Mtx& _m1, const Mtx& _m2)
{
	Mtx outMtx;
	core::MtxMulImpl(outMtx.vector, _m1.vector, _m2.vector);
	return outMtx;
}

Mtx MtxTranspose(const Mtx& _m)
{
	Mtx outMtx;
	core::MtxTransposeImpl(outMtx.vector, _m.vector);
	return outMtx;
}

Mtx MtxTranslation(const Vec4& _v)
{
	Mtx outMtx;
	core::MtxTranslationImpl(outMtx.vector, _v.vector);
	return outMtx;
}

Mtx MtxRotation(const Vec4& _v, const ROTATION_ORDER _rotationOrder)
{
	Mtx outMtx;
	switch (_rotationOrder)
	{
	case ROTATION_ORDER::XYZ:	core::MtxRotationXYZImpl(outMtx.vector, _v.vector);	break;
	case ROTATION_ORDER::XZY:	core::MtxRotationXZYImpl(outMtx.vector, _v.vector);	break;
	case ROTATION_ORDER::YXZ:	core::MtxRotationYXZImpl(outMtx.vector, _v.vector);	break;
	case ROTATION_ORDER::YZX:	core::MtxRotationYZXImpl(outMtx.vector, _v.vector);	break;
	case ROTATION_ORDER::ZXY:	core::MtxRotationZXYImpl(outMtx.vector, _v.vector);	break;
	case ROTATION_ORDER::ZYX:	core::MtxRotationZYXImpl(outMtx.vector, _v.vector);	break;
	}
	return outMtx;
}
Mtx MtxRotationZXY(const Vec4& _v)
{
	Mtx outMtx;
	core::MtxRotationZXYImpl(outMtx.vector, _v.vector);
	return outMtx;
}
Mtx MtxRotationZYX(const Vec4& _v)
{
	Mtx outMtx;
	core::MtxRotationZYXImpl(outMtx.vector, _v.vector);
	return outMtx;
}

Mtx MtxRotationQuat(const Quat& _q)
{
	Mtx outMtx;
	core::MtxRotationQuatImpl(outMtx.vector, _q.vector);
	return outMtx;
}

Mtx MtxScaling(const Vec4& _v)
{
	Mtx outMtx;
	core::MtxScalingImpl(outMtx.vector, _v.vector);
	return outMtx;
}

Mtx MtxOrthographic(const f32 _width, const f32 _height, const f32 _near, const f32 _far)
{
	Mtx outMtx;
	core::MtxOrthographicImpl(outMtx.vector, _width, _height, _near, _far);
	return outMtx;
}

Mtx MtxPerspective(const f32 _fov, const f32 _aspectRatio, const f32 _near, const f32 _far)
{
	Mtx outMtx;
	core::MtxPerspectiveImpl(outMtx.vector, _fov, _aspectRatio, _near, _far);
	return outMtx;
}

Mtx MtxLookAt(const Vec4& _view, const Vec4& _lookAt, const Vec4& _up)
{
	Mtx outMtx;
	core::MtxLookToImpl(outMtx.vector, _view.vector, VecSub(_lookAt, _view).vector, _up.vector);
	return outMtx;
}

Mtx MtxLookTo(const Vec4& _view, const Vec4& _lookDir, const Vec4& _up)
{
	Mtx outMtx;
	core::MtxLookToImpl(outMtx.vector, _view.vector, _lookDir.vector, _up.vector);
	return outMtx;
}

CANDY_NAMESPACE_END
