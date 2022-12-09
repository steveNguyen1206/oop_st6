#pragma once
#include "IShape.h"
#include <sstream>
#include <math.h>

class Square : public IShape
{
public:
	Square(double a);
	~Square() {};

private:
	double _a;

public:
	std::string toString();
	double area();
	double perimeter();

};
