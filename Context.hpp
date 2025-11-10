#pragma once

// See https://sourceforge.net/p/predef/wiki/Standards.
#define STANDARD_OTHER 0
#define STANDARD_CPP11 201103l
#define STANDARD_CPP14 201402l
#define STANDARD_CPP17 201703l
#define STANDARD_CPP20 202002l
#define STANDARD_CPP23 202302l

// See https://sourceforge.net/p/predef/wiki/Compilers.
#define COMPILER_OTHER 0
#define COMPILER_CLANG 1
#define COMPILER_GCC 2
#define COMPILER_MSVC 3

// See https://sourceforge.net/p/predef/wiki/OperatingSystems.
#define OPERATING_SYSTEM_OTHER 0
#define OPERATING_SYSTEM_LINUX 1
#define OPERATING_SYSTEM_WINDOWS 2

// See https://sourceforge.net/p/predef/wiki/Architectures.
#define ARCHITECTURE_OTHER 0
#define ARCHITECTURE_AMD64 1
#define ARCHITECTURE_INTEL_X86 2

#if defined(_MSVC_LANG)
	#define STANDARD _MSVC_LANG
#elif
	#define STANDARD __cplusplus
#endif

#if defined(__clang__)
	#define COMPILER COMPILER_CLANG
#elif defined(__GNUC__)
	#define COMPILER COMPILER_GCC
#elif defined(_MSC_VER)
	#define COMPILER COMPILER_MSVC
#else
	#define COMPILER COMPILER_OTHER
#endif

#if defined(__gnu_linux__)
	#define OPERATING_SYSTEM OPERATING_SYSTEM_LINUX
#elif defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
	#define OPERATING_SYSTEM OPERATING_SYSTEM_WINDOWS
#else
	#define OPERATING_SYSTEM OPERATING_SYSTEM_OTHER
#endif

#if defined(__amd64) || defined(__amd64__) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
	#define ARCHITECTURE ARCHITECTURE_AMD64
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386)
	#define ARCHITECTURE ARCHITECTURE_INTEL_X86
#else
	#define ARCHITECTURE ARCHITECTURE_OTHER
#endif