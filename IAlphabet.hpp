#ifndef IALPHABET_HPP
#define IALPHABET_HPP

#include <string>
#include <map>

namespace alphabet
{
   struct IAlphabet
   {
      using startLetter = char;
      using codingLetter = char;
      using codingMap = std::map<startLetter, codingLetter>;
      using decodingMap = std::map<codingLetter, startLetter>;

      IAlphabet(){ }
      IAlphabet(const codingMap& alphabet)
         : mCodingAlphabet(alphabet)
      {
         for(auto codingPair :  mCodingAlphabet )
         {
            decodingAlphabet.insert({codingPair.second, codingPair.first});
         }

      }

      ~IAlphabet(){}

      bool setStartAlphabet(const std::string& startAlphabet);
      bool setCodingAlphabet(const std::string& codingAlphabet);

      char getCodingLetter(char letter);
      char getDecodingLetter(char letter);

   private:
      codingMap mCodingAlphabet;
      decodingMap decodingAlphabet;
      bool isAlghabetComplete;
   };
}

#endif // IALPHABET_HPP
