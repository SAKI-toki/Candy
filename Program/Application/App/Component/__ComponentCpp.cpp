/*****************************************************************//**
 * \file   __ComponentCpp.cpp
 * \brief  コンポーネントのcppファイル結合
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#include "ComponentBase.cpp"

#include "System/List/ComponentList.cpp"
#include "System/Manager/ComponentManager.cpp"
#include "System/Table/ComponentPriorityTable.cpp"
#include "System/Table/ComponentRequireTable.cpp"

#include "Behavior/BehaviorBaseComponent.cpp"
#include "Behavior/PlayerBehaviorComponent.cpp"
#include "Behavior/EnemyBehaviorComponent.cpp"

#include "Renderer/RendererBaseComponent.cpp"
#include "Renderer/SpriteRendererComponent.cpp"
#include "Renderer/ModelRendererComponent.cpp"

#include "Transform/TransformComponent.cpp"

#include "Camera/CameraBaseComponent.cpp"
#include "Camera/Camera2dComponent.cpp"
#include "Camera/Camera3dComponent.cpp"
