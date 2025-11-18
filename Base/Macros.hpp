// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

#define ABORT() std::abort()

#ifdef NDEBUG
	#define ASSERT(expression)
	#define BREAKPOINT()
#else
	#include <cassert>

	// See https://stackoverflow.com/a/49079078.
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
#endif