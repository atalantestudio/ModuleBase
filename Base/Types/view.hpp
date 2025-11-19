// Copyright 2025 Atalante.
// Licensed under MIT.

#pragma once

#include "Types/base_view.hpp"

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

			// TODO: Add support for versions below C++17.
			CONSTEXPR_CPP17 view<char8>(const char8* data) :
				view<char8>(data, std::char_traits<char8>::length(data))
			{}

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
	};
}