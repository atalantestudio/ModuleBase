// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

namespace atl {
	template<typename T>
	inline void copy(const T* sourceBegin, const T* sourceEnd, T* destination) {
		std::copy(sourceBegin, sourceEnd, destination);
	}
}