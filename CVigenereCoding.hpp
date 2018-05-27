#ifndef CVIGENERECODING_HPP
#define CVIGENERECODING_HPP

#include "ICodingProcessor.hpp"

class CVigenereCoding : public ICodingProcessor
{
public:
   CVigenereCoding();
   explicit CVigenereCoding(const std::string& key);

   virtual ~CVigenereCoding() {}

   virtual void codingText(std::string& codingText) override;
   virtual void decodingText(std::string& decodingText) override;

private :
   void initKey();

private:
   std::string mKey;
};

#endif // CVIGENERECODING_HPP
