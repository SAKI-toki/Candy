/*****************************************************************//**
 * \file   Global.cpp
 * \brief  グローバルなパラメータ群
 * \author Yu Ishiyama.
 * \date   2022/06/01
 *********************************************************************/

#include "Global.h"
#include <Core/Time/Time.h>

CANDY_APP_NAMESPACE_BEGIN

namespace Global
{
	core::Tick m_PrevFrameTick;
	f32 m_AppTime = 0.0f;
	f32 m_AppTimeAll = 0.0f;
}

// 初期化
void Global::Startup()
{

}

// 破棄
void Global::Cleanup()
{

}

// 更新
void Global::Update()
{
	const auto tick = core::Time::GetTick();
	m_AppTime = core::Min((tick - m_PrevFrameTick).toSec(), core::Config::GetMaxAppTime());
	m_PrevFrameTick = tick;
	m_AppTimeAll += m_AppTime;
}

// 前フレームの経過時間の取得
f32 Global::GetAppTime()
{
	return m_AppTime;
}

// トータルのフレームの経過時間の取得
f32 Global::GetAppTimeAll()
{
	return m_AppTimeAll;
}

CANDY_APP_NAMESPACE_END
