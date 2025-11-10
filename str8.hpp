#pragma once

namespace ProjectA {
	class str8 : public buffer<char8> {
		public:
			str8() = default;

			explicit str8(uint64 count) :
				buffer(count)
			{}

			str8(const char8* string) :
				buffer(std::strlen(string))
			{
				std::copy_n(string, count(), begin());
			}

			str8(const std::string& string) :
				buffer(string.size())
			{
				std::copy_n(&string[0], count(), begin());
			}

			str8(const buffer<char8>& buffer) :
				buffer(buffer)
			{}

			str8(buffer<char8>&& buffer) :
				buffer(buffer)
			{}

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