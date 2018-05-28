#ifndef LETTERCOORD_HPP
#define LETTERCOORD_HPP


struct LetterCoord
{
   LetterCoord();

public:

   bool isInit() const;

   int getLineNumber() const;
   void setLineNumber(int value);

   int getColumNumber() const;
   void setColumNumber(int value);

private:
   int lineNumber;
   int columNumber;
   bool isLineInit;
   bool isColumInit;
};

#endif // LETTERCOORD_HPP
