// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

namespace USER_NAMESPACE {
	// TODO(upgrade): Allocate from arena.
	template<typename T>
	class base_sequence {
		protected:
			static T* allocate(uint64 count) {
				return new T[count]();
			}

			static void free(const T* data) {
				delete[] data;
			}

		public:
			base_sequence<T>() = default;

			explicit base_sequence<T>(uint64 count) :
				_count(count),
				_data(allocate(_count))
			{}

			base_sequence<T>(std::initializer_list<T> list) :
				base_sequence<T>(list.size())
			{
				copy(list.begin(), list.end(), _data);
			}

			base_sequence<T>(const base_sequence<T>& sequence) :
				base_sequence<T>(sequence._count)
			{
				copy(sequence.begin(), sequence.end(), _data);
			}

			base_sequence<T>(base_sequence<T>&& sequence) noexcept :
				_count(sequence._count)
			{
				_data = sequence._data;

				sequence._count = 0;
				sequence._data = nullptr;
			}

			~base_sequence<T>() {
				free(_data);
			}

			void operator=(const base_sequence<T>& sequence) {
				free(_data);

				_count = sequence._count;
				_data = allocate(_count);

				copy(sequence.begin(), sequence.end(), _data);
			}

			void operator=(base_sequence<T>&& sequence) noexcept {
				ASSERT(_data != sequence._data);

				_count = sequence._count;
				_data = sequence._data;

				sequence._count = 0;
				sequence._data = nullptr;
			}

			uint64 count() const {
				return _count;
			}

			const T& operator[](uint64 index) const {
				ASSERT(index < _count);

				return _data[index];
			}

			T& operator[](uint64 index) {
				ASSERT(index < _count);

				return _data[index];
			}

			const T* begin() const {
				return _data;
			}

			T* begin() {
				return _data;
			}

			const T* end() const {
				return _data + _count;
			}

			T* end() {
				return _data + _count;
			}

		protected:
			uint64 _count = 0;
			T* _data = nullptr;
	};
}