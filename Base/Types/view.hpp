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

			index find(char8 character, index characterOffset) const {
				while (characterOffset < count()) {
					if (_data[characterOffset] == character) {
						break;
					}

					characterOffset += 1;
				}

				return characterOffset;
			}

			index find(view<char8> view, index characterOffset) const {
				index characterIndex;
				index viewCharacterIndex;

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

			friend std::ostream& operator<<(std::ostream& stream, view<char8> view) {
				// TODO: Handle width, fill character, alignment, etc.
				return stream.write(&view[0], view.count());
			}
	};

	// The EOF character is included in the result.
	inline index getPostReplacementCharacterCount(view<char8> text, view<char8> pattern, view<char8> replacement) {
		index offset = 0;
		index patternCount = 0;

		while (offset < text.count()) {
			offset = text.find(pattern, offset) + pattern.count();

			patternCount += 1;
		}

		return text.count() + patternCount * (static_cast<sint32>(replacement.count()) - static_cast<sint32>(pattern.count()));
	}

	inline sequence<char8> replace(view<char8> text, view<char8> pattern, view<char8> replacement) {
		const index count = getPostReplacementCharacterCount(text, pattern, replacement);

		sequence<char8> replacedText(count);
		index offset = 0;
		index nextOffset = 0;
		index replacedOffset = 0;

		while (offset < text.count()) {
			nextOffset = text.find(pattern, offset);

			const char8* end = text.end();

			if (nextOffset < text.count()) {
				end = &text[nextOffset];
			}

			copy(&text[offset], end, &replacedText[replacedOffset]);

			replacedOffset += nextOffset - offset;

			if (replacedOffset + 1 >= replacedText.count()) {
				break;
			}

			copy(replacement.begin(), replacement.end(), &replacedText[replacedOffset]);

			replacedOffset += replacement.count();
			offset = nextOffset + pattern.count();
		}

		return replacedText;
	}
}