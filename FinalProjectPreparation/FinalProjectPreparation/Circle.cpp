#include "Circle.h"


Circle::Circle(double r)
{
	if (r > 0)
		_radius = r;
	else _radius = 0;
}


std::string Circle::toString()
{
	std::stringstream builder;
	builder << std::fixed << std::setprecision(PRCECISION) << "Circle"
		<< " r=" << _radius;
	//	<< ": are=" << area()
	//	<< ": premieter=" << perimeter() << std::endl;

	std::string result = builder.str();
	return result;
}

double Circle::area()
{
	return PI * pow(_radius, 2);
}

double Circle::perimeter()
{
	return 2 * PI * _radius;
}