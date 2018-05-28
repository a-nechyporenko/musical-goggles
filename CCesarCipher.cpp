#include "CCesarCipher.hpp"
#include <iostream>

nCesar::CCesarCipher::CCesarCipher(std::shared_ptr<IAlphabet> alphabet, const int offset) :
	mOffset(offset)
	, mKey(alphabet->symbolSequence())
	, mDec(alphabet->symbolSequence())
{
	addAlphabet(alphabet);
}

nCesar::CCesarCipher::~CCesarCipher()
{
}

void nCesar::CCesarCipher::decipher(std::vector<char>& context)
{
	for (int i = 0; i < context.size(); ++i)
	{
		context[i] = mKey[context[i]];
	}
}

void nCesar::CCesarCipher::cipher(std::vector<char>& context)
{	
	for (int i = 0; i < context.size(); ++i)
	{
		context[i] = mDec[context[i]];
	}
}

void nCesar::CCesarCipher::setOffset(int offset)
{
	mOffset = offset;
}

void nCesar::CCesarCipher::addAlphabet(std::shared_ptr<IAlphabet> alphabet)
{
	char temp;
	char beta;
	for (int i = 0; i < mOffset; ++i)
	{
		for (auto iter = alphabet->getFirstSymbol(); iter < alphabet->getLastSymbol(); ++iter)
		{
			if (iter == alphabet->getFirstSymbol())
			{
				temp = mKey[iter + 1];
				mKey[iter + 1] = mKey[iter];
			}
			else
			{
				beta = mKey[iter + 1];
				mKey[iter + 1] = temp;
				temp = beta;
			}
		}
		mKey[alphabet->getFirstSymbol()] = temp;
	}

	for (int i = 0; i < mOffset; ++i)
	{
		for (auto iter = alphabet->getLastSymbol(); iter > alphabet->getFirstSymbol(); --iter)
		{
			if (iter == alphabet->getLastSymbol())
			{
				temp = mDec[iter - 1];
				mDec[iter - 1] = mDec[iter];
			}
			else
			{
				beta = mDec[iter - 1];
				mDec[iter - 1] = temp;
				temp = beta;
			}
		}
		mDec[alphabet->getLastSymbol()] = temp;
	}
}