#include "CircleParser.h"
#include "Utils.h"


Object* CircleParser::parse(std::string str)
{
	std::string delim = "=";
	std::vector<std::string> tokens = Utils::String::split(str, delim);
	double radius = std::stod(tokens[1]);
	Object* p = new Circle(radius);
	return p;
}


std::string CircleParser::parserdObjectName()
{
	std::string res = "Circle";
	return res;
}

std::string CircleParser::toString()
{
	return "Circle Parser";
}
