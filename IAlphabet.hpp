#pragma once

#include <unordered_map>

namespace nCesar
{
	class IAlphabet
	{
	public:
		IAlphabet();
		virtual ~IAlphabet() = default;

		virtual const int symbolCount() const = 0;
		virtual char getFirstSymbol() const = 0;
		virtual char getLastSymbol() const = 0;
		virtual std::unordered_map<char, char> symbolSequence() const = 0;
	};
}