#ifndef CTRISEMUSCODING_HPP
#define CTRISEMUSCODING_HPP

#include "ICodingProcessor.hpp"
#include <vector>

struct LetterCoord;


class CTrisemusCoding : public ICodingProcessor
{
public:
   CTrisemusCoding();
   virtual ~CTrisemusCoding(){}

   virtual void codingText(std::string& codingText) override;
   virtual void decodingText(std::string& decodingText) override;

   virtual const char* getName() const override { return "Trisemus"; }

private:
   void init();
   void initKey();
   void initCipherTable();

   char codingLetter(char letter);
   char decodingLetter(char letter);

   LetterCoord getLetterIndex(char letter);

private:
   std::vector<std::string> mCipherTable;
   std::string mKey;
   int COUNT_TABLE_COLUM;
   int COUNT_TABLE_LINES;
   char mIgnorLetter;
};

#endif // CTRISEMUSCODING_HPP
