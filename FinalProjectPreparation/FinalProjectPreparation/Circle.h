#pragma once
#include "IShape.h"
#include <sstream>
#include <math.h>
#define PI 3.141593

class Circle : public IShape
{
public:
	Circle(double r);
	~Circle() {};

private:
	double _radius;

public:
	std::string toString();
	double area();
	double perimeter();

};
