// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

// TODO: It may be better to create a custom struct, e.g. ViewHasher.
template<>
struct std::hash<atl::view<atl::char8>> {
	std::size_t operator()(const atl::view<atl::char8>& key) const {
		const std::size_t dataHash = std::hash<const void*>{}(key.begin());
		const std::size_t countHash = std::hash<atl::uint64>{}(key.count());

		return dataHash ^ (countHash + 0x9e3779b97f4a7c15ULL + (dataHash << 6) + (dataHash >> 2));
	}
};