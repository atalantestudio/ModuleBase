// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

#define ABORT() std::abort()

// See https://stackoverflow.com/a/49079078.
#if BUILD_MODE == BUILD_MODE_DEBUG
	#include <cassert>

	#if COMPILER == COMPILER_CLANG
		#if __has_builtin(__builtin_debugtrap)
			#define BREAKPOINT() __builtin_debugtrap()
		#else
			#define BREAKPOINT()
		#endif
	#elif COMPILER == COMPILER_GCC
		#define BREAKPOINT() __builtin_trap()
	#elif COMPILER == COMPILER_MSVC
		#define BREAKPOINT() __debugbreak()
	#else
		#define BREAKPOINT()
	#endif

	#define ASSERT(expression) assert(expression)
#else
	#define ASSERT(expression)
	#define BREAKPOINT()
#endif