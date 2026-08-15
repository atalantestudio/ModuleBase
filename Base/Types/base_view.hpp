// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace atl {
	template<typename T>
	class base_view {
		public:
			/// Constructs an empty view.
			base_view() = default;

			/// Constructs a view of a single element.
			constexpr base_view(const T& data) :
				base_view<T>(&data, 1)
			{}

			/// Constructs a view of a static array of C elements.
			template<uint64 C>
			constexpr base_view(const T (&data)[C]) :
				_count(C),
				_data(data)
			{}

			/// Constructs a view of a dynamically allocated sequence.
			base_view(const base_sequence<T>& sequence) :
				base_view<T>(&sequence[0], sequence.count())
			{}

			/// Constructs a view of the first `count` elements, starting at `data`.
			constexpr explicit base_view(const T* data, uint64 count) :
				_count(count),
				_data(data)
			{}

			uint64 count() const {
				return _count;
			}

			const T& operator[](uint64 index) const {
				ATL_ASSERT(index == 0 || index < _count);

				return _data[index];
			}

			const T* begin() const {
				return _data;
			}

			const T* end() const {
				return _data + _count;
			}

		protected:
			uint64 _count = 0;
			const T* _data = nullptr;
	};
}