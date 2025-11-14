// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

// Returns a number with a single set bit at `index`.
#define BIT(index) (1 << (index))

namespace USER_NAMESPACE {
	// Returns the minimum number of bits necessary to store `value`.
	inline uint8 countBits(uint64 value) {
		uint8 bitCount = 0;

		while (value) {
			bitCount += 1;

			value >>= 1;
		}

		return bitCount;
	}

	// Returns the number of set bits in `value`.
	// See https://web.archive.org/web/20151229003112/http://blogs.msdn.com/b/jeuge/archive/2005/06/08/hakmem-bit-count.aspx.
	inline uint8 countSetBits(uint32 value) {
		value -= (value >> 1 & 0xdb6db6db) + (value >> 2 & 0x49249249);

		const uint8 setBitCount = static_cast<uint8>((value + (value >> 3) & 0xc71c71c7) % 63);

		return setBitCount;
	}
}