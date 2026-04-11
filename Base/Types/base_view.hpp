// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace atl {
	template<typename T>
	class base_view {
		public:
			/// Constructs an empty view.
			base_view() = default;

			/// Constructs a view of 1 element.
			constexpr base_view(const T& element) :
				base_view<T>(&element, 1)
			{}

			/// Constructs a view of the first `count` elements pointed by `data`.
			constexpr explicit base_view(const T* data, uint64 count) :
				_count(count),
				_data(data)
			{}

			/// Constructs a view covering the full range of `sequence`.
			base_view(const base_sequence<T>& sequence) :
				base_view<T>(&sequence[0], sequence.count())
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