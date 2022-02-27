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