#ifndef ICODINGPROCESSOR_HPP
#define ICODINGPROCESSOR_HPP

#include <string>

class ICodingProcessor
{
public:
   ICodingProcessor(){}
   virtual ~ICodingProcessor(){}

   virtual void codingText(std::string& codingText) = 0;
   virtual void decodingText(std::string& decodingText) = 0;

};

#endif // ICODINGPROCESSOR_HPP
