#include "CUserInterface.hpp"

#include "Helper.hpp"
#include "CAtbashCoding.hpp"
#include "CGronsfeldCoding.hpp"
#include "CVigenereCoding.hpp"
#include "CTrisemusCoding.hpp"
//#include "CPolibiiCoding.hpp"

#include <iostream>
#include <string>

CUserInterface::CUserInterface()
   : mParagraph(nConstants::FIRST_PARAGRAPH)
{
}

CUserInterface::~CUserInterface()
{
}

void CUserInterface::startMenu()
{
   char button = '0';
   mParagraph = nConstants::FIRST_PARAGRAPH;

   std::cout << "Cesar cripher <---\n"
             << "Gronsfeld cripher\n"
             << "Vigener cripher\n"
             << "Trisemus cripher"
             << "Atbash cripher"
             << "Exit";

   while (button != nConstants::ENTER)
   {
      button = getch();

      switch (button)
      {
         case nConstants::UP: --mParagraph;
            checkParagraph();
            outMenu();
         break;
         case nConstants::DOWN: ++mParagraph;
            checkParagraph();
            outMenu();
         break;
         default: break;
      }
   }

   outParagraph();
}

void CUserInterface::outMenu()
{
   switch (mParagraph)
   {
   case nConstants::FIRST_PARAGRAPH: system("cls");
      std::cout << "Cesar cripher <---\n"
         << "Gronsfeld cripher\n"
         << "Vigener cripher\n"
         << "Trisemus cripher\n"
         << "Atbash cripher\n"
         << "Exit\n";
      break;
   case nConstants::SECOND_PARAGRAPH: system("cls");
      std::cout << "Cesar cripher\n"
         << "Gronsfeld cripher <---\n"
         << "Vigener cripher\n"
         << "Trisemus cripher\n"
         << "Atbash cripher\n"
         << "Exit\n";
      break;
   case nConstants::THIRD_PARAGRAPH: system("cls");
      std::cout << "Cesar cripher\n"
         << "Gronsfeld cripher\n"
         << "Vigener cripher <---\n"
         << "Trisemus cripher\n"
         << "Atbash cripher\n"
         << "Exit\n";
      break;
   case nConstants::FOURTH_PARAGRAPH: system("cls");
      std::cout << "Cesar cripher\n"
         << "Gronsfeld cripher\n"
         << "Vigener cripher\n"
         << "Trisemus cripher <---\n"
         << "Atbash cripher\n"
         << "Exit\n";
      break;
      case nConstants::FIFTH_PARAGRAPH: system("cls");
         std::cout << "Cesar cripher\n"
            << "Gronsfeld cripher\n"
            << "Vigener cripher\n"
            << "Trisemus cripher\n"
            << "Atbash cripher <---\n"
            << "Exit\n";
         break;
      case nConstants::SIXTH_PARAGRAPH: system("cls");
         std::cout << "Cesar cripher\n"
            << "Gronsfeld cripher\n"
            << "Vigener cripher\n"
            << "Trisemus cripher\n"
            << "Atbash cripher\n"
            << "Exit <---\n";
         break;
   default: break;
   }
}

void CUserInterface::checkParagraph()
{
   if (mParagraph < nConstants::FIRST_PARAGRAPH)
   {
      mParagraph = nConstants::SIXTH_PARAGRAPH;
   }
   if (mParagraph > nConstants::SIXTH_PARAGRAPH)
   {
      mParagraph = nConstants::FIRST_PARAGRAPH;
   }
}

void CUserInterface::outParagraph()
{
   switch (mParagraph)
   {
      case nConstants::FIRST_PARAGRAPH:
      {
         system("cls");
      }
      break;
      case nConstants::SECOND_PARAGRAPH:
      {
         system("cls");
      }
      break;
      case nConstants::THIRD_PARAGRAPH:
      {
         system("cls");
      }
      break;
      case nConstants::FOURTH_PARAGRAPH:
      {
         system("cls");
      }
      break;
      case nConstants::FIFTH_PARAGRAPH:
      {
         system("cls");
      }
      break;
      case nConstants::SIXTH_PARAGRAPH:
      {
         exit(0);
      }
      break;
      default: break;
   }
}

void CUserInterface::demonstrateCripher(ICodingProcessor* cripher)
{
   std::cout <<"Start " << cripher->getName() << " coding test : \n";
   std::string text;

   cout << "Input coding text : ";
   cin >> text;
   cout << "\n Your text : " << text.c_str() <<"\n";

   cripher->codingText(text);

   cout << "\n Your coding text : " << text.c_str() <<"\n";

   cripher->decodingText(text);

   cout << "\n Your decoding text : " << text.c_str() <<"\n";
}
