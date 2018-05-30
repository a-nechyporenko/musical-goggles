#ifndef ATBASHCODING_HPP
#define ATBASHCODING_HPP

#include"ICodingProcessor.hpp"
#include <string>
#include <map>

class CAtbashCoding : public ICodingProcessor
{
private:
   enum class eCodingMod
   {
      CODING = 0,
      DECODING = 1
   };

public:
   CAtbashCoding();

   virtual void init() override;

   virtual void codingText(std::string& text) override;
   virtual void decodingText(std::string& text) override;

   virtual const char* getName() const override { return "Atbash"; }

   char codingLetter(char letter);
   char decodingLetter(char letter);

private:
   void initMapsForCoding();
   void processingText(std::string& text, const eCodingMod mod);
   char processingLetter(char letter, const std::map<char,char>& processingMap) const;

private:
   std::map<char, char> codingMap;
   std::map<char, char> decodingMap;
   std::string codingAlphabet;
};

#endif // ATBASHCODING_HPP
