#pragma once

#include "IAlphabet.hpp"

namespace nCesar
{
	class ICryptographer
	{
	public:
		ICryptographer();
		virtual ~ICryptographer() = default;

		virtual void decipher(std::vector<char>& context) = 0;
		virtual void cipher(std::vector<char>& context) = 0;
		virtual void setOffset(int offset) = 0;
	};
}