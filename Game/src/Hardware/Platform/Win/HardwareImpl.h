#ifndef CANDY_HARDWARE_IMPL_H
#define CANDY_HARDWARE_IMPL_H

CANDY_NAMESPACE_BEGIN

namespace Hardware::Impl
{
	struct StartupInfo
	{
		virtual ~StartupInfo() = default;

		HINSTANCE m_InstanceHandle;
		int m_CmdShowNum;
		std::string m_Name;
		f32 m_Width;
		f32 m_Height;
	};

	void Startup(const StartupInfo& _startupInfo);
	void Cleanup();

	void Update();

	bool IsClose();
}

CANDY_NAMESPACE_END

#endif // CANDY_HARDWARE_IMPL_H
