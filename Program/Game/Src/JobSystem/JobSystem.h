/*****************************************************************//**
 * \file   JobSystem.h
 * \brief  ジョブシステム
 * \author Yu Ishiyama.
 * \date   2022/06/07
 *********************************************************************/

#ifndef CANDY_JOB_SYSTEM_H
#define CANDY_JOB_SYSTEM_H

CANDY_NAMESPACE_BEGIN

class JobSystem
{
public:
	void startup();
	void cleanup();
};

CANDY_NAMESPACE_END

#endif // CANDY_JOB_SYSTEM_H
