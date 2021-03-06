#pragma once

#ifdef FT_PLATFORM_WINDOWS
	#ifdef FT_BUILD_DLL
		#define FLINT_API __declspec(dllexport)
	#else
		#define FLINT_API __declspec(dllimport)
	#endif
#else
	#error Flintstone only supports windows
#endif

#ifdef FT_ENABLE_ASSERTS
	#define FT_ASSERT(x, ...) { if(!(x)) { FT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FT_CORE_ASSERT(x, ...) { if(!(x)) {FT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FT_ASSERT(x, ...)
	#define FT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)