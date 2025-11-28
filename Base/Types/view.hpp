// Copyright 2025 Atalante Studio.
// Distributed under the MIT License.

#pragma once

#include "base_view.hpp"

namespace atl {
	template<typename T>
	class view : public base_view<T> {
		public:
			using base_view<T>::base_view;
	};

	template<>
	class view<char8> : public base_view<char8> {
		public:
			using base_view<char8>::base_view;

			constexpr view<char8>(const char8* data) :
				view<char8>(data, countCharacters(data))
			{}

			#if ATL_STANDARD >= ATL_STANDARD_CPP17
				constexpr view<char8>(std::string_view stringView) :
					view<char8>(stringView.data(), stringView.size())
				{}
			#endif

			bool operator==(view<char8> other) const {
				return _count == other._count && std::strncmp(_data, other._data, _count) == 0;
			}

			bool operator!=(view<char8> other) const {
				return !operator==(other);
			}

			uint64 find(char8 character, uint64 characterOffset) const {
				while (characterOffset < count()) {
					if (_data[characterOffset] == character) {
						break;
					}

					characterOffset += 1;
				}

				return characterOffset;
			}

			uint64 find(view<char8> view, uint64 characterOffset) const {
				uint64 characterIndex;
				uint64 viewCharacterIndex;

				while (characterOffset < count()) {
					if (view.count() > count() - characterOffset) {
						return count();
					}

					characterIndex = characterOffset;
					viewCharacterIndex = 0;

					while (_data[characterIndex] == view[viewCharacterIndex]) {
						characterIndex += 1;
						viewCharacterIndex += 1;

						if (characterIndex >= count() || viewCharacterIndex >= view.count()) {
							return characterOffset;
						}
					}

					characterOffset += 1;
				}

				return characterOffset;
			}

			#if ATL_STANDARD >= ATL_STANDARD_CPP17
				operator std::string_view() const {
					return std::string_view(_data, _count);
				}
			#endif
	};
}