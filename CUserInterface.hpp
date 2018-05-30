#ifndef C_USER_INTERFACE_HPP
#define C_USER_INTERFACE_HPP

#include "ICodingProcessor.hpp"

class CUserInterface
{
public:
   CUserInterface();
   ~CUserInterface();

   void startMenu();

private:
   void outMenu();
   void outParagraph();
   void checkParagraph();
   void demonstrateCripher(ICodingProcessor* cripher);

private:
   int mParagraph;
   ICodingProcessor* pTrisemusCipher;
   ICodingProcessor* pCesarCipher;
   ICodingProcessor* pVigenerCipher;
   ICodingProcessor* pGronsfelddCipher;
   ICodingProcessor* pAtbashCipher;
};

#endif // C_USER_INTERFACE_HPP
