#pragma once

#include "IAlphabet.hpp"

namespace nCesar 
{
	class CEnglish : public IAlphabet
	{
	public:
		CEnglish();
		~CEnglish();

		const int symbolCount() const override;
		virtual char getFirstSymbol() const override;
		virtual char getLastSymbol() const override;
		std::unordered_map<char, char> symbolSequence() const override;
	private:
		std::unordered_map<char, char> mSymbols;
		char mSymbol;
	};
}