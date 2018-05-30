#include "CTrisemusCoding.hpp"
#include "LetterCoord.hpp"
#include <iostream>

CTrisemusCoding::CTrisemusCoding()
   : mCipherTable()
   , mKey()
   , COUNT_TABLE_COLUM(5)
   , COUNT_TABLE_LINES(5)
{
}

void CTrisemusCoding::codingText(std::string& codingText)
{
   std::cout <<"coding..." << "\n";
   std::string textAfterCoding;

   for(auto letter : codingText)
   {
      std::cout << letter << "->" << codingLetter(letter) << "\n";
      textAfterCoding.push_back(codingLetter(letter));
   }
   codingText.clear();
   codingText = textAfterCoding;
}

void CTrisemusCoding::decodingText(std::string& decodingText)
{
   std::cout <<"decoding..." << "\n";
   std::string textAfterDecoding;

   for(auto letter : decodingText)
   {
      std::cout << letter << "->" << decodingLetter(letter) << "\n";
      textAfterDecoding.push_back(decodingLetter(letter));
   }

   decodingText = textAfterDecoding;
}

void CTrisemusCoding::init()
{
   initKey();
   initCipherTable();
}

void CTrisemusCoding::initKey()
{
   std::string inputKey;
   system("cls");
   std::cout << "Please enter cypher key : ";
   std::cin >> inputKey;

   for (std::size_t i = 0; i < inputKey.size(); ++i)
   {
      char inputLetter  = std::tolower(inputKey[i]);

      if(std::string::npos == mKey.find(inputLetter))
      {
         if (inputLetter >= 'a' && inputLetter <= 'z')
         {
            mKey += inputLetter;
         }
      }
   }

   std::cout << "\n Cipher key : " << mKey << "\n";
}

void CTrisemusCoding::initCipherTable()
{
   std::string alphabet(mKey);

   for(char letter = 'a'; letter <= 'z'; ++letter)
   {
      if(std::string::npos == alphabet.find(letter))
      {
         alphabet.push_back(letter);
      }
   }

   auto it = alphabet.cbegin();

   std::cout << "Cipher table :\n";

   for(int i = 0; i < CTrisemusCoding::COUNT_TABLE_LINES; ++i)
   {
      std::string line;

      for(int j = 0; j < CTrisemusCoding::COUNT_TABLE_COLUM; ++j)
      {
         std::cout << *it;
         line.push_back(*it);
         ++it;
      }

      std::cout << "\n";

      mCipherTable.push_back(std::move(line));
   }

   mIgnorLetter = alphabet.back();

   std::cout << "Letter that will be ignored during cripher  : " << mIgnorLetter << "\n";
}

char CTrisemusCoding::codingLetter(char letter)
{
   bool isUpper = false;
   char cripherLetter = letter;
   LetterCoord letterCoord;

   if(true == std::isupper(letter))
   {
      letter = std::tolower(letter);
      letterCoord = getLetterIndex(std::toupper(letter));
      isUpper = true;
   }
   else
   {
      letterCoord = getLetterIndex(letter);
   }

   if(true == letterCoord.isInit())
   {
      const int LINES = mCipherTable.size() - 1;
      if(LINES > letterCoord.getLineNumber())
      {
         cripherLetter = mCipherTable[letterCoord.getLineNumber() + 1].at(letterCoord.getColumNumber());
      }
      else
      {
         cripherLetter = mCipherTable[0].at(letterCoord.getColumNumber());
      }
   }

   return ((true == isUpper) ? std::toupper(cripherLetter) : cripherLetter);
}

char CTrisemusCoding::decodingLetter(char letter)
{
   bool isUpper = false;
   char cripherLetter = letter;
   LetterCoord letterCoord;

   if(true == std::isupper(letter))
   {
      letter = std::tolower(letter);
      letterCoord = getLetterIndex(std::toupper(letter));
      isUpper = true;
   }
   else
   {
      letterCoord = getLetterIndex(letter);
   }

   if(true == letterCoord.isInit())
   {
      if(0 != letterCoord.getLineNumber())
      {
         cripherLetter = mCipherTable[letterCoord.getLineNumber() - 1].at(letterCoord.getColumNumber());
      }
      else
      {
         cripherLetter = mCipherTable[mCipherTable.size() - 1].at(letterCoord.getColumNumber());
      }
   }

   return ((true == isUpper) ? std::toupper(cripherLetter) : cripherLetter);
}

LetterCoord CTrisemusCoding::getLetterIndex(char letter)
{
   LetterCoord letterCoord;

   for(int i = 0; i < mCipherTable.size(); ++i)
   {
      auto columNumber = mCipherTable[i].find(letter);

      if(std::string::npos != columNumber)
      {
         letterCoord.setLineNumber(i);
         letterCoord.setColumNumber(columNumber);
         break;
      }
   }

   return letterCoord;
}
