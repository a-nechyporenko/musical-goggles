#ifndef CGRONSFELDCODING_HPP
#define CGRONSFELDCODING_HPP

#include "ICodingProcessor.hpp"
#include <list>

class CGronsfeldCoding : public ICodingProcessor
{
private :
   enum class eMod
   {
      CODING = 0,
      DECODING
   };

public:
   CGronsfeldCoding();
   virtual ~CGronsfeldCoding(){}

   virtual void codingText(std::string& codingText) override;
   virtual void decodingText(std::string& decodingText) override;

   virtual const char* getName() const override { return "Gronsfeld"; }

private:
   void init();
   void processingText(std::string& text,CGronsfeldCoding::eMod mod);
   char proccesingLetter(char letter, int key, eMod mod);

private:
   std::string mAlphabet;
   std::list<int> mKeyList;
};

#endif // CGRONSFELDCODING_HPP
