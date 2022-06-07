/*****************************************************************//**
 * \file   MainFlow.h
 * \brief  メインフロー
 * \author Yu Ishiyama.
 * \date   2022/05/31
 *********************************************************************/

#ifndef CANDY_MAIN_FLOW_H
#define CANDY_MAIN_FLOW_H

CANDY_NAMESPACE_BEGIN

namespace MainFlow
{
	// 初期化
	void Startup();
	// 破棄
	void Cleanup();
	// 更新
	void Update();

	// 終了判定
	bool IsEnd();
}

CANDY_NAMESPACE_END

#endif // CANDY_MAIN_FLOW_H
