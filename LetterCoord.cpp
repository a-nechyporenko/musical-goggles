#include "LetterCoord.hpp"

LetterCoord::LetterCoord()
   : lineNumber(0)
   , columNumber(0)
   , isLineInit(false)
   , isColumInit(false)
{}

bool LetterCoord::isInit() const
{
   return ((true == isLineInit) && (true == isColumInit));
}

int LetterCoord::getLineNumber() const
{
   return lineNumber;
}

void LetterCoord::setLineNumber(int value)
{
   isLineInit = true;
   lineNumber = value;
}

int LetterCoord::getColumNumber() const
{
   return columNumber;
}

void LetterCoord::setColumNumber(int value)
{
   isColumInit = true;
   columNumber = value;
}
