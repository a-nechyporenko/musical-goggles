#include "CEnglish.hpp"
#include <iostream>

nCesar::CEnglish::CEnglish() :
	mSymbol('a')
{
	char symbol = 'a';
	for (int i = 0; i < 26; ++i)
	{
		mSymbols[symbol] = symbol;
		++symbol;
	}
}

nCesar::CEnglish::~CEnglish()
{
}

const int nCesar::CEnglish::symbolCount() const
{
	return 26;
}

char nCesar::CEnglish::getFirstSymbol() const
{
	return 'a';
}

char nCesar::CEnglish::getLastSymbol() const
{
	return 'z';
}

std::unordered_map<char, char> nCesar::CEnglish::symbolSequence() const
{
	return mSymbols;
}
