#pragma once

namespace ProjectA {
	template<typename T>
	inline void copy(const T* sourceBegin, const T* sourceEnd, T* destination) {
		std::copy(sourceBegin, sourceEnd, destination);
	}
}