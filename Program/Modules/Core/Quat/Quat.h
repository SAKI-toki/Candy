/*****************************************************************//**
 * \file   Quat.h
 * \brief  Quaternion定義
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_CORE_QUAT_H
#define CANDY_CORE_QUAT_H

#include <Core/CoreInclude.h>

#include <Core/Vec/Vec4.h>

CANDY_NAMESPACE_BEGIN

struct Quat : Vec4
{
	using Vec4::Vec4;
};

CANDY_NAMESPACE_END

#endif // CANDY_CORE_QUAT_H
