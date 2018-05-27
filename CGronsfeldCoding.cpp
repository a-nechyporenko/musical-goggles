#include "CGronsfeldCoding.hpp"
#include <iostream>

CGronsfeldCoding::CGronsfeldCoding()
   : mAlphabet("abcdefghijklmnopqrstuvwxyz")
   , mKeyList()
{
   init();
}

void CGronsfeldCoding::init()
{
   int key;
   std::cout << "Enter koding key(your student card number):";
   std::cin >> key;

   while(0 != key)
   {
      mKeyList.push_front(key%10);
      key = key/10;
   }
}

void CGronsfeldCoding::decodingText(std::string& decodingText)
{
   processingText( decodingText, CGronsfeldCoding::eMod::DECODING);
}

void CGronsfeldCoding::codingText(std::string& codingText)
{
   processingText( codingText, CGronsfeldCoding::eMod::CODING);
}

void CGronsfeldCoding::processingText(std::string& text,CGronsfeldCoding::eMod mod )
{
   std::string textAfterProcessing;

   auto it = mKeyList.cbegin();
   auto endOfList = mKeyList.cend();

   for(auto letter : text)
   {
      textAfterProcessing.push_back(proccesingLetter(letter, *it,  mod));
      (it != endOfList) ? it = mKeyList.begin() :  ++it;
   }

   text = textAfterProcessing;
}

char CGronsfeldCoding::proccesingLetter(char letter, int key, CGronsfeldCoding::eMod mod)
{
   bool isUpper = false;
   if(true == std::isupper(letter))
   {
      letter = std::tolower(letter);
      isUpper = true;
   }
   auto LetterPos = mAlphabet.find(letter);
   static const int ALPHABET_SIZE = mAlphabet.size();

   char processingLetter = ' ';
   int shift = 0;

   switch (mod)
   {
      case eMod::CODING:
      {
         shift = LetterPos + key;

         if(ALPHABET_SIZE < shift )
         {
            shift = shift - ALPHABET_SIZE;
         }
      }
      break;

      case eMod::DECODING:
      {
         shift = LetterPos - key;

         if( 0 > shift )
         {
            shift = ALPHABET_SIZE + shift;
         }
      }
      break;
   }

   return  (true == isUpper) ? std::toupper(mAlphabet[shift]) : mAlphabet[shift];
}
