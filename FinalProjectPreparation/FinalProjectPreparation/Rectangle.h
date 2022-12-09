#pragma once
#include "IShape.h"
#include <sstream>
#include <math.h>

class Rectangle : public IShape
{
public:
	Rectangle(double width, double height);
	~Rectangle() {};

private:
	double _width;
	double _height;

public:
	std::string toString();
	double area();
	double perimeter();

};
