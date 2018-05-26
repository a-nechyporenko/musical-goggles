#include "CAtbashCoding.hpp"
#include <iostream>

CAtbashCoding::CAtbashCoding()
   : codingMap()
   , decodingMap()
   , codingAlphabet("zyxwvutsrqponmlkjihgfedcba")
{
   initMapsForCoding();
}

void CAtbashCoding::initMapsForCoding()
{
   int i = 0;
   std::cout << "Coding alphabet :\n";

   for(char letter = 'a'; letter <= 'z'; ++letter)
   {
      std::pair<char, char> codingPair(letter, codingAlphabet.at(i));
      std::pair<char, char> decodingPair(codingAlphabet.at(i),letter);

      std::cout << codingPair.first << "->"<< codingPair.second << "\n";

      codingMap.insert(codingPair);
      decodingMap.insert(decodingPair);
      ++i;
   }
}

void CAtbashCoding::codingText(std::string& text)
{
   processingText(text, eCodingMod::CODING);
}

char CAtbashCoding::codingLetter(char letter)
{
   return processingLetter(letter, codingMap);
}

void CAtbashCoding::decodingText(std::string& text)
{
   processingText(text, eCodingMod::DECODING);
}

char CAtbashCoding::decodingLetter(char letter)
{
   return processingLetter(letter, decodingMap);
}

void CAtbashCoding::processingText(std::string& text, const eCodingMod mod)
{
   std::string decodingText(text);
   const int LETTER_COUNT = decodingText.size();
   text.clear();

   std::cout << "Start coding : \n";

   for(int indx = 0; indx < LETTER_COUNT; ++indx)
   {
      auto letterForCoding = decodingText.at(indx);
      std::cout << letterForCoding;
      if( false == std::isdigit(letterForCoding))
      {
         switch (mod)
         {
         case eCodingMod::CODING:
            text.push_back(codingLetter(letterForCoding));
            break;
         case eCodingMod::DECODING:
            text.push_back(decodingLetter(letterForCoding));
            break;
         }
      }
      else
      {
         std::cout  << " (isnt letter) ";
         text.push_back(letterForCoding);
      }
      std::cout  << " -> " << text.back() << "\n";
   }
}

char CAtbashCoding::processingLetter(char letter, const std::map<char,char>& processingMap) const
{
   if(true == std::isupper(letter))
   {
      letter = std::tolower(letter);
      auto decodingLetter = processingMap.find(letter)->second;
      letter = std::toupper(decodingLetter);
   }
   else
   {
      letter = processingMap.find(letter)->second;
   }

   return letter;
}
