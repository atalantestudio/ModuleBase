// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

// See https://sourceforge.net/p/predef/wiki/Standards.
#define ATL_STANDARD_OTHER 0
#define ATL_STANDARD_CPP11 201103l
#define ATL_STANDARD_CPP14 201402l
#define ATL_STANDARD_CPP17 201703l
#define ATL_STANDARD_CPP20 202002l
#define ATL_STANDARD_CPP23 202302l

#if defined(_MSVC_LANG)
	#define ATL_STANDARD _MSVC_LANG
#else
	#define ATL_STANDARD __cplusplus
#endif

// See https://sourceforge.net/p/predef/wiki/Compilers.
#define ATL_COMPILER_OTHER 0
#define ATL_COMPILER_CLANG 1
#define ATL_COMPILER_GCC 2
#define ATL_COMPILER_MSVC 3

#if defined(__clang__)
	#define ATL_COMPILER ATL_COMPILER_CLANG
#elif defined(__GNUC__)
	#define ATL_COMPILER ATL_COMPILER_GCC
#elif defined(_MSC_VER)
	#define ATL_COMPILER ATL_COMPILER_MSVC
#else
	#define ATL_COMPILER ATL_COMPILER_OTHER
#endif

// See https://sourceforge.net/p/predef/wiki/OperatingSystems.
#define ATL_OPERATING_SYSTEM_OTHER 0
#define ATL_OPERATING_SYSTEM_LINUX 1
#define ATL_OPERATING_SYSTEM_WINDOWS 2

#if defined(__gnu_linux__)
	#define ATL_OPERATING_SYSTEM ATL_OPERATING_SYSTEM_LINUX
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
	#define ATL_OPERATING_SYSTEM ATL_OPERATING_SYSTEM_WINDOWS
#else
	#define ATL_OPERATING_SYSTEM ATL_OPERATING_SYSTEM_OTHER
#endif

// See https://sourceforge.net/p/predef/wiki/Architectures.
#define ATL_ARCHITECTURE_OTHER 0
#define ATL_ARCHITECTURE_AMD64 1
#define ATL_ARCHITECTURE_INTEL_X86 2

#if defined(__amd64) || defined(__amd64__) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
	#define ATL_ARCHITECTURE ATL_ARCHITECTURE_AMD64
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
	#define ATL_ARCHITECTURE ATL_ARCHITECTURE_INTEL_X86
#else
	#define ATL_ARCHITECTURE ATL_ARCHITECTURE_OTHER
#endif

#if ATL_STANDARD >= ATL_STANDARD_CPP17
	#define ATL_CONSTEXPR_CPP17 constexpr
#else
	#define ATL_CONSTEXPR_CPP17
#endif