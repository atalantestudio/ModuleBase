// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "base_sequence.hpp"
#include "base_view.hpp"

namespace atl {
	// A container that encapsulates a dynamic size array.
	// Unlike `std::vector<T>`, `sequence<T>` is not resizeable.
	// It *should* be used when the number of elements is known at runtime, before creating the sequence.
	// 
	// NOTE: `T` **must** expose a default constructor.
	template<typename T>
	class sequence : public base_sequence<T> {
		public:
			using base_sequence<T>::base_sequence;
	};

	template<>
	class sequence<char8> : public base_sequence<char8> {
		public:
			using base_sequence<char8>::base_sequence;

			explicit sequence<char8>(const char8* data, uint64 count) :
				sequence<char8>(count + 1)
			{
				_count -= 1;

				copy(data, data + _count, _data);
			}

			sequence<char8>(const char8* data) :
				sequence<char8>(data, countCharacters(data))
			{}

			sequence<char8>(base_view<char8> view) :
				sequence<char8>(&view[0], view.count())
			{}

			sequence<char8>(const std::string& string) :
				sequence<char8>(string.data(), string.size())
			{}

			sequence<char8>(const sequence<char8>& _sequence) :
				sequence<char8>(&_sequence[0], _sequence.count())
			{}

			void operator=(const sequence<char8>& _sequence) {
				free(_data);

				_count = _sequence._count;
				_data = allocate(_count + 1);

				copy(_sequence.begin(), _sequence.end(), _data);
			}

			operator std::string() const {
				return std::string(_data, _count);
			}
	};
}