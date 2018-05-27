#include <iostream>
#include <string>
#include "CAtbashCoding.hpp"
#include "CGronsfeldCoding.hpp"
//#include "CPolibiiCoding.hpp"

using namespace std;

void checkAbashCoding();
//void checkPolibiaCoding();
void checkGroverCoding();

int main()
{
   setlocale(LC_ALL, "russian");
   system("cls");

   checkGroverCoding();
   return 0;
}

void checkAbashCoding()
{
   std::cout <<"Start Abash coding test : \n";
   CAtbashCoding Abashcoder;
   std::string text;
   cout << "Input coding text : ";
   cin >> text;
   cout << "\n Your text : " << text.c_str() <<"\n";

   Abashcoder.codingText(text);

   cout << "\n Your coding text : " << text.c_str() <<"\n";

   Abashcoder.decodingText(text);

   cout << "\n Your decoding text : " << text.c_str() <<"\n";
}

//void checkPolibiaCoding()
//{
//   std::cout <<"Start Polibia coding test : \n";
//   CPolibiiCoding polibiCoder;
//   std::string text;
//   cout << "Input coding text : ";
//   cin >> text;
//   cout << "\n Your text : " << text.c_str() <<"\n";

//   polibiCoder.codingText(text);

//   cout << "\n Your coding text : " << text.c_str() <<"\n";

//   polibiCoder.decodingText(text);

//   cout << "\n Your decoding text : " << text.c_str() <<"\n";
//}

void checkGroverCoding()
{
   std::cout <<"Start Gronsfeld coding test : \n";
   CGronsfeldCoding groverCoder;
   std::string text;
   cout << "Input coding text : ";
   cin >> text;
   cout << "\n Your text : " << text.c_str() <<"\n";

   groverCoder.codingText(text);

   cout << "\n Your coding text : " << text.c_str() <<"\n";

   groverCoder.decodingText(text);

   cout << "\n Your decoding text : " << text.c_str() <<"\n";
}
