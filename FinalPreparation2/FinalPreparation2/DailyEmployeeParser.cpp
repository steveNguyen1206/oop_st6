#include "DailyEmployeeParser.h"

std::string DailyEmployeeParser::toString()
{
	return "Daily employee parser";
}


Object* DailyEmployeeParser::parse(std::string str)
{
	std::string delim = ", ";
	std::vector<std::string> tokens = Utils::String::split(str, delim);

	std::string buffer = tokens[0];
	delim = "=";
	int dayCount = std::stoi(Utils::String::split(buffer, delim)[1]);
	buffer = tokens[1];
	int paymentPerDay = std::stoi(Utils::String::split(buffer, delim)[1]);
	Object* p = new DailyEmployee(dayCount, paymentPerDay);
	return p;
}


std::string DailyEmployeeParser::parserdObjectName()
{
	return "DailyEmployee";
}