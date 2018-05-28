#include <iostream>
#include <string>
#include "ICodingProcessor.hpp"
#include "CAtbashCoding.hpp"
#include "CGronsfeldCoding.hpp"
#include "CVigenereCoding.hpp"
#include "CTrisemusCoding.hpp"
//#include "CPolibiiCoding.hpp"

using namespace std;

void checkCipherProcessor(ICodingProcessor* cipherProcessor);

int main()
{
   setlocale(LC_ALL, "russian");
   system("cls");

   ICodingProcessor* vignere = new CTrisemusCoding();

   checkCipherProcessor(vignere);

   delete vignere;

   return 0;
}

void checkCipherProcessor(ICodingProcessor* cipherProcessor)
{
   std::cout <<"Start " << cipherProcessor->getName() << " coding test : \n";
   std::string text;

   cout << "Input coding text : ";
   cin >> text;
   cout << "\n Your text : " << text.c_str() <<"\n";

   cipherProcessor->codingText(text);

   cout << "\n Your coding text : " << text.c_str() <<"\n";

   cipherProcessor->decodingText(text);

   cout << "\n Your decoding text : " << text.c_str() <<"\n";
}
