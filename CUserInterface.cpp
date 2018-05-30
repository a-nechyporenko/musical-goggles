#include "CUserInterface.hpp"

#include "Helper.hpp"
#include "CAtbashCoding.hpp"
#include "CGronsfeldCoding.hpp"
#include "CVigenereCoding.hpp"
#include "CTrisemusCoding.hpp"

#include <iostream>
#include <string>
#include <conio.h>

CUserInterface::CUserInterface()
   : mParagraph(nConstants::CESAR_CRIPHER)
   , pTrisemusCipher(new CTrisemusCoding)
//   , pCesarCipher(new CCesarCoding)
   , pVigenerCipher(new CVigenereCoding)
   , pGronsfelddCipher(new CGronsfeldCoding)
   , pAtbashCipher(new CAtbashCoding)
{
}

CUserInterface::~CUserInterface()
{
   delete pTrisemusCipher;
   delete pCesarCipher;
   delete pVigenerCipher;
   delete pGronsfelddCipher;
   delete pAtbashCipher;
}

void CUserInterface::startMenu()
{
   char button = '0';
   mParagraph = nConstants::CESAR_CRIPHER;

   std::cout << "Cesar cripher <---\n"
             << "Gronsfeld cripher \n"
             << "Vigener cripher \n"
             << "Trisemus cripher \n"
             << "Atbash cripher \n"
             << "Exit \n";

   while (button != nConstants::ENTER)
   {
      button = _getch();

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
   case nConstants::CESAR_CRIPHER: system("cls");
      std::cout << "Cesar cripher <---\n"
         << "Gronsfeld cripher\n"
         << "Vigener cripher\n"
         << "Trisemus cripher\n"
         << "Atbash cripher\n"
         << "Exit\n";
      break;
   case nConstants::GRONSFELD_CIPHER: system("cls");
      std::cout << "Cesar cripher\n"
         << "Gronsfeld cripher <---\n"
         << "Vigener cripher\n"
         << "Trisemus cripher\n"
         << "Atbash cripher\n"
         << "Exit\n";
      break;
   case nConstants::VIGENER_CIPHER: system("cls");
      std::cout << "Cesar cripher\n"
         << "Gronsfeld cripher\n"
         << "Vigener cripher <---\n"
         << "Trisemus cripher\n"
         << "Atbash cripher\n"
         << "Exit\n";
      break;
   case nConstants::TRISEMUS_CIPHER: system("cls");
      std::cout << "Cesar cripher\n"
         << "Gronsfeld cripher\n"
         << "Vigener cripher\n"
         << "Trisemus cripher <---\n"
         << "Atbash cripher\n"
         << "Exit\n";
      break;
      case nConstants::ATBASH_CIPHER: system("cls");
         std::cout << "Cesar cripher\n"
            << "Gronsfeld cripher\n"
            << "Vigener cripher\n"
            << "Trisemus cripher\n"
            << "Atbash cripher <---\n"
            << "Exit\n";
         break;
      case nConstants::EXIT: system("cls");
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
   if (mParagraph < nConstants::CESAR_CRIPHER)
   {
      mParagraph = nConstants::EXIT;
   }
   if (mParagraph > nConstants::EXIT)
   {
      mParagraph = nConstants::CESAR_CRIPHER;
   }
}

void CUserInterface::outParagraph()
{
   switch (mParagraph)
   {
      case nConstants::CESAR_CRIPHER:
      {
         system("cls");
         demonstrateCripher(pCesarCipher);
      }
      break;
      case nConstants::GRONSFELD_CIPHER:
      {
         system("cls");
         demonstrateCripher(pGronsfelddCipher);
      }
      break;
      case nConstants::VIGENER_CIPHER:
      {
         system("cls");
         demonstrateCripher(pVigenerCipher);
      }
      break;
      case nConstants::TRISEMUS_CIPHER:
      {
         system("cls");
         demonstrateCripher(pTrisemusCipher);
      }
      break;
      case nConstants::ATBASH_CIPHER:
      {
         system("cls");
         demonstrateCripher(pAtbashCipher);
      }
      break;
      case nConstants::EXIT:
      {
         system("cls");
         std::cout << "Finish application \n" ;
         exit(0);
      }
      break;
      default: break;
   }
   system("pause");
   system("cls");
   startMenu();
}

void CUserInterface::demonstrateCripher(ICodingProcessor* cripher)
{
   std::cout <<"Start " << cripher->getName() << " coding test : \n";

   cripher->init();

   std::string text;

   std::cout << "Input coding text : ";
   std::cin >> text;
   std::cout << "\n Your text : " << text.c_str() <<"\n";

   cripher->codingText(text);

   std::cout << "\n Your coding text : " << text.c_str() <<"\n";

   cripher->decodingText(text);

   std::cout << "\n Your decoding text : " << text.c_str() <<"\n";
}
