/*****************************************************************//**
 * \file   __PhysicsCpp.cpp
 * \brief  Phisics関連のcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "Collision2D/PhysicsCollision2D_LineLine.cpp"
#include "Collision2D/PhysicsCollision2D_TriangleTriangle.cpp"
#include "Collision2D/PhysicsCollision2D_QuadQuad.cpp"
#include "Collision2D/PhysicsCollision2D_RayCast.cpp"

#include "Module/PhysicsModule.cpp"

#include "Shapde2D/Line/PhysicsShape2DLine.cpp"
#include "Shapde2D/Triangle/PhysicsShape2DTriangle.cpp"
#include "Shapde2D/Quad/PhysicsShape2DQuad.cpp"
#include "Shapde2D/Ray/PhysicsShape2DRay.cpp"
