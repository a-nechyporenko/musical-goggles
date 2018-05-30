#pragma once

#include <memory>
#include <unordered_map>

#include "ICodingProcessor.hpp"
#include "IAlphabet.hpp"

namespace nCesar
{
   class CCesarCipher : public ICodingProcessor
	{
	public:
      explicit CCesarCipher(std::shared_ptr<IAlphabet> alphabet);
		CCesarCipher(std::shared_ptr<IAlphabet> alphabet, const int offset);
		~CCesarCipher();

      virtual void init() override;

      virtual void codingText(std::string& codingText) override;
      virtual void decodingText(std::string& decodingText) override;
      virtual const char* getName() const override {return "Cesar cipher";}

      void setOffset(int offset);

	private:
		void addAlphabet(std::shared_ptr<IAlphabet> alphabet);

		int mOffset;
		std::unordered_map<char, char> mKey;
		std::unordered_map<char, char> mDec;
      std::shared_ptr<IAlphabet> mAlphabet;
	};
}
