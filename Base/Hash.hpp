// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

// TODO: It may be better to create a custom struct, e.g. ViewHasher.
template<>
struct std::hash<atl::view<atl::char8>> {
	std::size_t operator()(const atl::view<atl::char8>& key) const {
		std::size_t hash = 14695981039346656037;
		atl::uint64 characterIndex = 0;

		while (characterIndex < key.count()) {
			hash ^= key[characterIndex];
			hash *= 1099511628211;

			characterIndex += 1;
		}

		return hash;
	}
};