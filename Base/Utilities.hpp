// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

namespace atl {
	template<typename T>
	inline void copy(const T* sourceBegin, const T* sourceEnd, T* destination) {
		std::copy(sourceBegin, sourceEnd, destination);
	}

	inline uint64 countCharacters(const char8* string) {
		uint64 count = 0;

		while (true) {
			if (string[count] == '\0') {
				break;
			}

			count += 1;
		}

		return count;
	}
}