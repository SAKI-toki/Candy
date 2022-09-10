﻿/*****************************************************************//**
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

#include "Behavior/PlayerBehaviorComponent.cpp"
#include "Behavior/EnemyBehaviorComponent.cpp"

#include "Renderer/RendererComponent.cpp"

#include "Transform/TransformComponent.cpp"