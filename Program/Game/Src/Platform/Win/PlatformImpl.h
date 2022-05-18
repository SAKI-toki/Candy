#ifndef CANDY_PLATFORM_IMPL_H
#define CANDY_PLATFORM_IMPL_H

#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <xaudio2.h>
#include <xaudio2fx.h>
#include <wrl/client.h>
#include <xmmintrin.h>

CANDY_NAMESPACE_BEGIN

template<typename T>
using ComPtr = Microsoft::WRL::ComPtr<T>;

#define CANDY_ASSERT_HRESULT(EXPR) \
{ \
	const HRESULT candyAssertHresult = (EXPR); \
	if(FAILED(candyAssertHresult)) \
	{ \
		CANDY_LOG("0x%08x", candyAssertHresult); CANDY_ASSERT(false); \
	} \
}

#define MAKE_FOURCC(x, y, z, w) (((w) << 24) | ((z) << 16) | ((y) << 8) | (x))

CANDY_NAMESPACE_END

#endif // CANDY_PLATFORM_IMPL_H
