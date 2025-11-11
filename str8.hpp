#pragma once

namespace ProjectA {
	class str8 : public buffer<char8> {
		public:
			str8() = default;

			explicit str8(uint64 count) :
				buffer(count)
			{}

			// NOTE: Returns a null-terminated string.
			str8(const char8* characters) :
				buffer(std::strlen(characters) + 1)
			{
				// Exclude '\0' from the character count.
				_count -= 1;

				std::copy_n(characters, _count, begin());

				pointer[_count] = '\0';
			}

			str8(const std::string& string) :
				buffer(string.size() + 1)
			{
				// Exclude '\0' from the character count.
				_count -= 1;

				std::copy(string.begin(), string.end(), begin());

				pointer[_count] = '\0';
			}

			str8(const buffer<char8>& buffer) :
				buffer(buffer.count() + 1)
			{
				// Exclude '\0' from the character count.
				_count -= 1;

				std::copy(buffer.begin(), buffer.end(), begin());

				pointer[_count] = '\0';
			}

			str8(buffer<char8>&& buffer) :
				buffer(buffer)
			{}

			str8& operator =(const str8& string) {
				delete[] pointer;

				pointer = new char8[string._count + 1]();
				_count = string._count;

				std::copy(string.begin(), string.end(), pointer);

				pointer[_count] = '\0';

				return *this;
			}

			uint64 find(char8 character, uint64 characterOffset) const {
				while (characterOffset < count()) {
					if (operator[](characterOffset) == character) {
						break;
					}

					characterOffset += 1;
				}

				return characterOffset;
			}

			uint64 find(const str8& string, uint64 characterOffset) const {
				uint64 characterIndex;
				uint64 stringCharacterIndex;

				while (characterOffset < count()) {
					if (string.count() > count() - characterOffset) {
						return count();
					}

					characterIndex = characterOffset;
					stringCharacterIndex = 0;

					while (operator[](characterIndex) == string[stringCharacterIndex]) {
						characterIndex += 1;
						stringCharacterIndex += 1;

						if (characterIndex >= count() || stringCharacterIndex >= string.count()) {
							return characterOffset;
						}
					}

					characterOffset += 1;
				}

				return characterOffset;
			}
	};
}