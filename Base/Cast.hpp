// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace atl {
	template<typename O, typename I>
	inline O function_cast(I function) {
		return reinterpret_cast<O>(reinterpret_cast<void (*)()>(function));
	}

	template<typename O, typename I>
	inline typename std::enable_if<std::is_const<typename std::remove_pointer<O>::type>::value, O>::type pointer_cast(I pointer) {
		return static_cast<O>(static_cast<const void*>(pointer));
	}

	template<typename O, typename I>
	inline typename std::enable_if<!std::is_const<typename std::remove_pointer<O>::type>::value, O>::type pointer_cast(I pointer) {
		return static_cast<O>(static_cast<void*>(pointer));
	}
}