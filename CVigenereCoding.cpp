#include "CVigenereCoding.hpp"
#include <iostream>

CVigenereCoding::CVigenereCoding()
   : mKey()
{

}

CVigenereCoding::CVigenereCoding(const std::string& key)
   : mKey(key)
{

}

void CVigenereCoding::init()
{
   if( true == mKey.empty())
   {
      initKey();
   }
}

void CVigenereCoding::codingText(std::string& codingText)
{
   std::string out;

   for (int i = 0, j = 0; i < codingText.length(); ++i)
   {
      char c = codingText[i];

      if (c >= 'a' && c <= 'z')
      {
         c += 'A' - 'a';
      }

      if (c >= 'A' || c <= 'Z')
      {
         out += (c + mKey[j] - 2 * 'A') % 26 + 'A';

         j = (j + 1) % mKey.length();
      }
   }

   codingText = out;
}

void CVigenereCoding::decodingText(std::string& decodingText)
{
   std::string out;

   for (int i = 0, j = 0; i < decodingText.length(); ++i)
   {
      char c = decodingText[i];

      if (c >= 'a' && c <= 'z')
      {
         c += 'A' - 'a';
      }

      if (c >= 'A' || c <= 'Z')
      {
         out += (c - mKey[j] + 26) % 26 + 'A';

         j = (j + 1) % mKey.length();
      }
   }

   decodingText = out;
}

void CVigenereCoding::initKey()
{
   std::string inputKey;
   std::cout << "Please enter cypher key : ";
   std::cin >> inputKey;

   for (int i = 0; i < inputKey.size(); ++i)
   {
      if (inputKey[i] >= 'A' && inputKey[i] <= 'Z')
      {
         mKey += inputKey[i];
      }
      else
      {
         if (inputKey[i] >= 'a' && inputKey[i] <= 'z')
         {
            mKey += inputKey[i] + 'A' - 'a';
         }
      }
   }
   std::cout << "\n cypher key : " << mKey << "\n";
}

