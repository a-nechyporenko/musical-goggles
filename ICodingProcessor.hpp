#ifndef ICODINGPROCESSOR_HPP
#define ICODINGPROCESSOR_HPP

#include <string>

class ICodingProcessor
{
public:
   ICodingProcessor(){}
   virtual ~ICodingProcessor(){}

   virtual void init() = 0;

   virtual void codingText(std::string& codingText) = 0;
   virtual void decodingText(std::string& decodingText) = 0;
   virtual const char* getName() const = 0;
};

#endif // ICODINGPROCESSOR_HPP
