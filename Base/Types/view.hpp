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

			constexpr view(const char8* data) :
				view<char8>(data, countCharacters(data))
			{}

			#if ATL_STANDARD >= ATL_STANDARD_CPP17
				constexpr view(std::string_view stringView) :
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

	// Removes whitespace (' ' and '\') at the start of the text.
	// Line feeds are not trimmed.
	inline view<char8> trimLeft(view<char8> text) {
		index start = 0;

		while (start < text.count() && (text[start] == ' ' || text[start] == '\t')) {
			start += 1;
		}

		return view<char8>(&text[start], text.count() - start);
	}

	// Removes whitespace (' ' and '\') at the end of the text.
	// Line feeds are not trimmed.
	inline view<char8> trimRight(view<char8> text) {
		sint32 end = static_cast<sint32>(text.count()) - 1;

		while (end >= 0 && (text[end] == ' ' || text[end] == '\t')) {
			end -= 1;
		}

		return view<char8>(&text[0], end + 1);
	}

	// Removes whitespace (' ' and '\') around the text.
	// Line feeds are not trimmed.
	inline view<char8> trim(view<char8> text) {
		return trimLeft(trimRight(text));
	}

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

		sequence<char8> replacedText(count + 1);
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

	template<typename T>
	inline auto find(const std::unordered_map<sequence<char8>, T>& map, view<char8> key) {
		typename std::unordered_map<sequence<char8>, T>::const_iterator iterator = map.begin();

		while (iterator != map.end()) {
			if (iterator->first == key) {
				break;
			}

			iterator++;
		}

		return iterator;
	}
}