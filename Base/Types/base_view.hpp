// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

namespace atl {
	template<typename T>
	class base_view {
		public:
			base_view() = default;

			// TODO
			/* constexpr base_view<T>(const T* data) :
				base_view<T>(data, countElements<T>(data))
			{} */

			constexpr explicit base_view<T>(const T* data, uint64 count) :
				_count(count),
				_data(data)
			{}

			base_view<T>(const base_sequence<T>& sequence) :
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