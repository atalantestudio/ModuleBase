// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

#define ATL_ABORT() std::abort()

#ifdef NDEBUG
	#define ATL_ASSERT(expression)
	#define ATL_BREAKPOINT()
#else
	#include <cassert>

	// See https://stackoverflow.com/a/49079078.
	#if ATL_COMPILER == ATL_COMPILER_CLANG
		#if __has_builtin(__builtin_debugtrap)
			#define ATL_BREAKPOINT() __builtin_debugtrap()
		#else
			#define ATL_BREAKPOINT()
		#endif
	#elif ATL_COMPILER == ATL_COMPILER_GCC
		#define ATL_BREAKPOINT() __builtin_trap()
	#elif ATL_COMPILER == ATL_COMPILER_MSVC
		#define ATL_BREAKPOINT() __debugbreak()
	#else
		#define ATL_BREAKPOINT()
	#endif

	#define ATL_ASSERT(expression) assert(expression)
#endif