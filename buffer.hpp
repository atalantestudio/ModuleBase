#pragma once

namespace ProjectA {
	// An owning and non-resizeable array of elements of type `T`.
	// NOTE: `T` must expose a default constructor.
	template<typename T>
	class buffer {
		public:
			buffer() = default;

			explicit buffer(uint64 _count) :
				_count(_count),
				pointer(new T[_count]())
			{}

			buffer(const std::initializer_list<T>& list) :
				buffer(list.size())
			{
				std::copy(list.begin(), list.end(), pointer);
			}

			buffer(const buffer<T>& buffer) :
				buffer(buffer._count)
			{
				std::copy(buffer.begin(), buffer.end(), pointer);
			}

			buffer(buffer<T>&& buffer) :
				_count(buffer._count),
				pointer(buffer.pointer)
			{
				buffer.pointer = nullptr;
				buffer._count = 0;
			}

			~buffer() {
				delete[] pointer;
			}

			uint64 count() const {
				return _count;
			}

			buffer& operator =(const buffer<T>& buffer) {
				delete[] pointer;

				pointer = new T[buffer._count]();
				_count = buffer._count;

				std::copy(buffer.begin(), buffer.end(), pointer);

				return *this;
			}

			buffer& operator =(buffer<T>&& buffer) {
				pointer = buffer.pointer;
				_count = buffer._count;

				buffer.pointer = nullptr;
				buffer._count = 0;

				return *this;
			}

			const T& operator [](uint64 index) const {
				ASSERT(index == 0 || index < _count);

				return pointer[index];
			}

			T& operator [](uint64 index) {
				ASSERT(index == 0 || index < _count);

				return pointer[index];
			}

			const T* begin() const {
				return &pointer[0];
			}

			T* begin() {
				return &pointer[0];
			}

			const T* end() const {
				return &pointer[_count];
			}

			T* end() {
				return &pointer[_count];
			}

		private:
			uint64 _count = 0;
			T* pointer = nullptr;
	};
}