#include "NumberInformation.h"

std::string NumberFormatInfo::currencyDecimalSeparator()
{
	return ".";
}
std::string NumberFormatInfo::currencySymbol()
{
	return "d";
}

int NumberFormatInfo::currencyPositive()
{
	return 1;
}

std::string NumberFormatInfo::currencyPositiveFormat()
{
	return "n $";
}