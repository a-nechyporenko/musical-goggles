#pragma once

#include <memory>
#include <unordered_map>

#include "ICryptographer.hpp"

namespace nCesar
{
	class CCesarCipher : public ICryptographer
	{
	public:
		CCesarCipher(std::shared_ptr<IAlphabet> alphabet, const int offset);
		~CCesarCipher();

		void decipher(std::vector<char>& context) override;
		void cipher(std::vector<char>& context) override;
		void setOffset(int offset) override;
	private:
		void addAlphabet(std::shared_ptr<IAlphabet> alphabet);

		int mOffset;
		std::unordered_map<char, char> mKey;
		std::unordered_map<char, char> mDec;
	};
}