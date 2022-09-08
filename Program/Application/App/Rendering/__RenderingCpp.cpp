/*****************************************************************//**
 * \file   __RenderingCpp.cpp
 * \brief  レンダリングのcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "RenderingManager.cpp"

#include "Pass/RenderingPass_BeginFrame.cpp"
#include "Pass/RenderingPass_Debug2D.cpp"
#include "Pass/RenderingPass_EndFrame.cpp"
#include "Pass/RenderingPass_Model.cpp"
#include "Pass/RenderingPass_Sprite.cpp"

#include "Sprite/Sprite.cpp"
#include "Sprite/SpriteImpl.cpp"
#include "Sprite/SpriteRenderingManager.cpp"
