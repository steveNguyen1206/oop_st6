#include "RectangleParser.h"
#include "Utils.h"


Object* RectangleParser::parse(std::string str)
{
	std::string delim = ", ";
	std::vector<std::string> tokens = Utils::String::split(str, delim);

	std::string buffer = tokens[0];
	delim = "=";
	double width = std::stod(Utils::String::split(buffer, delim)[1]);
	buffer = tokens[1];
	double height = std::stod(Utils::String::split(buffer, delim)[1]);
	Object* p = new Rectangle(width, height);
	return p;
}


std::string RectangleParser::parserdObjectName()
{
	std::string res = "Rectangle";
	return res;
}

std::string RectangleParser::toString()
{
	return "Rectangle Parser";
}
