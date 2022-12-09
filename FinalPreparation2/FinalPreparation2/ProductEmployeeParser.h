#pragma once
#include "IParsable.h"
#include "ProductEmployee.h"

class ProductEmployeeParser : IParsable
{
public:

private:

public:
	std::string toString();
	Object* parse(std::string str);
	std::string parserdObjectName();
};

