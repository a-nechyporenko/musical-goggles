#ifndef ATBASHCODING_HPP
#define ATBASHCODING_HPP

#include <string>
#include <map>

class CAtbashCoding
{
private:
   enum class eCodingMod
   {
      CODING = 0,
      DECODING = 1
   };

public:
   CAtbashCoding();

   void codingText(std::string& text);
   void decodingText(std::string& text);

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
