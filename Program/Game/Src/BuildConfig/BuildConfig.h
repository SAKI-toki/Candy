#ifndef CANDY_BUILD_CONFIG_H
#define CANDY_BUILD_CONFIG_H

#if _DEBUG
#define BUILD_DEBUG (1)
#define BUILD_RELEASE (0)
#else
#define BUILD_DEBUG (0)
#define BUILD_RELEASE (1)
#endif // _DEBUG

#endif // CANDY_BUILD_CONFIG_H
