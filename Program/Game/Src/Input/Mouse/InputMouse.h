#ifndef CANDY_INPUT_MOUSE_H
#define CANDY_INPUT_MOUSE_H

#if PLATFORM_WIN
#include <Input/Platform/Win/Mouse/InputMouseImpl.h>
#endif // PLATFORM_WIN

CANDY_NAMESPACE_BEGIN

namespace Input
{
	class Mouse : public Impl::MouseImpl
	{
	public:
		void startup();
		void cleanup();

		void update();

		void reset();

		Vec4 getScreenPos()const;
		Vec4 getClientPos()const;
		Vec4 getPrevScreenPos()const;
		Vec4 getPrevClientPos()const;

	private:
		Vec4 m_ScreenPos{};
		Vec4 m_ClientPos{};
		Vec4 m_PrevScreenPos{};
		Vec4 m_PrevClientPos{};
	};
}

CANDY_NAMESPACE_END

#endif // CANDY_INPUT_MOUSE_H
