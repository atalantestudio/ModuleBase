// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace atl {
	template<typename T>
	struct Comparator {
		bool operator()(T a, T b) const;
	};

	template<>
	inline bool Comparator<view<char8>>::operator()(view<char8> a, view<char8> b) const {
		return a.begin() < b.begin();
	}
}