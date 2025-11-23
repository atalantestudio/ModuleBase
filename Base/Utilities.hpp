// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

#define ATL_MAX(a, b) a > b ? a : b
#define ATL_MIN(a, b) a < b ? a : b

namespace atl {
	template<typename T>
	inline void copy(const T* sourceBegin, const T* sourceEnd, T* destination) {
		std::copy(sourceBegin, sourceEnd, destination);
	}

	inline constexpr uint64 countCharacters(const char8* characters) {
		#if ATL_STANDARD >= ATL_STANDARD_CPP17
			return std::char_traits<char8>::length(characters);
		#else
			return *characters == '\0' ? 0 : 1 + countCharacters(characters + 1);
		#endif
	}
}