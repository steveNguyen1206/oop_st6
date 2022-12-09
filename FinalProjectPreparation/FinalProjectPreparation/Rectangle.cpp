#include "Rectangle.h"


Rectangle::Rectangle(double width, double height)
{
	if (width < 0)
		width = 0;
	if (height < 0)
		height = 0;

	_width = width;
	_height = height;
}



std::string Rectangle::toString()
{
	std::stringstream builder;
	builder << std::fixed << std::setprecision(PRCECISION) << "Rectangle"
		<< " w=" << _width
		<< ", h=" << _height;
	//	<< ": are=" << area()
	//	<< ": premieter=" << perimeter() << std::endl;

	std::string result = builder.str();
	return result;
}

double Rectangle::area()
{
	return _width * _height;
}

double Rectangle::perimeter()
{
	return 2 * (_width + _height);
}