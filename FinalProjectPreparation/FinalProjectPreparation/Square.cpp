#include "Square.h"


Square::Square(double a)
{
	if (a > 0)
		_a = a;
	else _a = 0;
}


std::string Square::toString()
{
	std::stringstream builder;
	builder << std::fixed << std::setprecision(PRCECISION) << "Square"
		<< " a=" << _a;
	//	<< ": are=" << area()
	//	<< ": premieter=" << perimeter() << std::endl;

	std::string result = builder.str();
	return result;
}

double Square::area()
{
	return _a * _a;
}

double Square::perimeter()
{
	return 4 * _a;
}