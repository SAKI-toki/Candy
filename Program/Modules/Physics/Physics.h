/*****************************************************************//**
 * \file   Physics.h
 * \brief  Physicsファイルのインクルード
 * \author Yu Ishiyama.
 * \date   2022/07/03
 *********************************************************************/

#ifndef CANDY_PHYSICS_H
#define CANDY_PHYSICS_H

#include "PhysicsInclude.h"

#include "Collision2D/PhysicsCollision2D_LineLine.h"
#include "Collision2D/PhysicsCollision2D_TriangleTriangle.h"
#include "Collision2D/PhysicsCollision2D_QuadQuad.h"
#include "Collision2D/PhysicsCollision2D_RayCast.h"

#include "Module/PhysicsModule.h"

#include "Shapde2D/Line/PhysicsShape2DLine.h"
#include "Shapde2D/Triangle/PhysicsShape2DTriangle.h"
#include "Shapde2D/Quad/PhysicsShape2DQuad.h"
#include "Shapde2D/Ray/PhysicsShape2DRay.h"

#endif // CANDY_PHYSICS_H
