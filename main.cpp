#include <iostream>
#include <string>
#include "CAtbashCoding.hpp"

using namespace std;

int main()
{
   std::cout <<"Start coding test : \n";
   CAtbashCoding coder;
   std::string text;
   cout << "Input coding text : ";
   cin >> text;
   cout << "\n Your text : " << text.c_str() <<"\n";

   coder.codingText(text);

   cout << "\n Your coding text : " << text.c_str() <<"\n";

   coder.decodingText(text);

   cout << "\n Your decoding text : " << text.c_str() <<"\n";

   return 0;
}
