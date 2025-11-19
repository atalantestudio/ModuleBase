// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

namespace atl {
	template<typename T>
	class base_view {
		public:
			explicit base_view() = default;

			base_view<T>(const base_sequence<T>& sequence) :
				_count(sequence.count()),
				_data(sequence.begin())
			{}

			constexpr explicit base_view<T>(const char8* data, uint64 count) :
				_count(count),
				_data(data)
			{}

			uint64 count() const {
				return _count;
			}

			const T& operator[](uint64 index) const {
				ASSERT(index < _count);

				return _data[index];
			}

			const T* begin() const {
				return _data;
			}

			const T* end() const {
				return _data + _count;
			}

		protected:
			const uint64 _count = 0;
			const T* _data = nullptr;
	};
}