#include "SquareParser.h"
#include "Utils.h"


Object* SquareParser::parse(std::string str)
{
	std::string delim = "=";
	std::vector<std::string> tokens = Utils::String::split(str, delim);
	double a = std::stod(tokens[1]);
	Object* p = new Square(a);
	return p;
}


std::string SquareParser::parserdObjectName()
{
	std::string res = "Square";
	return res;
}

std::string SquareParser::toString()
{
	return "Square Parser";
}
