#ifndef CANDY_MAIN_FLOW_H
#define CANDY_MAIN_FLOW_H

CANDY_NAMESPACE_BEGIN

namespace MainFlow
{
	void Startup();
	void Cleanup();
	void Update();

	bool IsEnd();
}

CANDY_NAMESPACE_END

#endif // CANDY_MAIN_FLOW_H
