#include "CCesarCipher.hpp"
#include <iostream>

nCesar::CCesarCipher::CCesarCipher(std::shared_ptr<IAlphabet> alphabet)
   : mOffset(0)
	, mKey(alphabet->symbolSequence())
	, mDec(alphabet->symbolSequence())
   , mAlphabet(alphabet)
{
   addAlphabet(alphabet);
}

nCesar::CCesarCipher::CCesarCipher(std::shared_ptr<IAlphabet> alphabet, const int offset)
   : mOffset(offset)
   , mKey(alphabet->symbolSequence())
   , mDec(alphabet->symbolSequence())
   , mAlphabet(alphabet)
{
   addAlphabet(alphabet);
}

nCesar::CCesarCipher::~CCesarCipher()
{
}

void nCesar::CCesarCipher::init()
{
   int inputKey(0);
   system("cls");
   std::cout << "Please enter cypher key : ";
   std::cin >> inputKey;
   setOffset(inputKey);
   addAlphabet(mAlphabet);
}

void nCesar::CCesarCipher::decodingText(std::string& decodingText)
{
   for (int i = 0; i < decodingText.size(); ++i)
	{
      decodingText[i] = mKey[decodingText[i]];
	}
}

void nCesar::CCesarCipher::codingText(std::string& codingText)
{	
   for (int i = 0; i < codingText.size(); ++i)
	{
      codingText[i] = mDec[codingText[i]];
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
