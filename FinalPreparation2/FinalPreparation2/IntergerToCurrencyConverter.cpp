#include "IntegerToCurrencyConverter.h"
#include <regex>

std::string IntegerToCurrencyConverter::convert(Object* object) {
	auto number = dynamic_cast<Integer*>(object);
	int value = number->value();

	std::stringstream builder;
	NumberFormatInfo info;
	int count = 0;

	while (value != 0) {
		int lastDigit = value % 10;
		builder << lastDigit;

		count++;

		if (count == 3) {
			builder << info.currencyDecimalSeparator();
			count = 0;
		}

		value /= 10;
	}

	std::string numberSeparated = builder.str(); // "000.000.1"
	reverse(numberSeparated.begin(), numberSeparated.end());

	std::string format = info.currencyPositiveFormat(); //"n $" ==> "1.000.000 d"
	std::string symbol = info.currencySymbol(); // "d"

	// https://stackoverflow.com/questions/17459450/how-to-determine-currency-symbol-position-for-a-culture
	std::string result = std::regex_replace(format, std::regex("n"), numberSeparated);
	result = std::regex_replace(result, std::regex("\\$"), symbol);

	return result;
}