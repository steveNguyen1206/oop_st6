#pragma once
#include "Object.h"

class IShape : public Object
{
public:


private:

public:
	virtual double area() = 0;
	virtual double perimeter() = 0;

};

