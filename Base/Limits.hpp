// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace atl {
	// Returns the minimum value representable by `T`.
	template<typename T>
	constexpr T min() noexcept;

	template<>
	constexpr sint8 min() noexcept {
		return INT8_MIN;
	}

	template<>
	constexpr sint16 min() noexcept {
		return INT16_MIN;
	}

	template<>
	constexpr sint32 min() noexcept {
		return INT32_MIN;
	}

	template<>
	constexpr sint64 min() noexcept {
		return INT64_MIN;
	}

	template<>
	constexpr uint8 min() noexcept {
		return 0;
	}

	template<>
	constexpr uint16 min() noexcept {
		return 0;
	}

	template<>
	constexpr uint32 min() noexcept {
		return 0;
	}

	template<>
	constexpr uint64 min() noexcept {
		return 0;
	}

	template<>
	constexpr float32 min() noexcept {
		return FLT_MIN;
	}

	template<>
	constexpr float64 min() noexcept {
		return DBL_MIN;
	}

	template<>
	constexpr char8 min() noexcept {
		return INT8_MIN;
	}

	template<>
	constexpr char16 min() noexcept {
		return INT16_MIN;
	}

	template<>
	constexpr char32 min() noexcept {
		return INT32_MIN;
	}

	// Returns the maximum value representable by `T`.
	template<typename T>
	constexpr T max() noexcept;

	template<>
	constexpr sint8 max() noexcept {
		return INT8_MAX;
	}

	template<>
	constexpr sint16 max() noexcept {
		return INT16_MAX;
	}

	template<>
	constexpr sint32 max() noexcept {
		return INT32_MAX;
	}

	template<>
	constexpr sint64 max() noexcept {
		return INT64_MAX;
	}

	template<>
	constexpr uint8 max() noexcept {
		return UINT8_MAX;
	}

	template<>
	constexpr uint16 max() noexcept {
		return UINT16_MAX;
	}

	template<>
	constexpr uint32 max() noexcept {
		return UINT32_MAX;
	}

	template<>
	constexpr uint64 max() noexcept {
		return UINT64_MAX;
	}

	template<>
	constexpr float32 max() noexcept {
		return FLT_MAX;
	}

	template<>
	constexpr float64 max() noexcept {
		return DBL_MAX;
	}

	template<>
	constexpr char8 max() noexcept {
		return INT8_MAX;
	}

	template<>
	constexpr char16 max() noexcept {
		return INT16_MAX;
	}

	template<>
	constexpr char32 max() noexcept {
		return INT32_MAX;
	}
}