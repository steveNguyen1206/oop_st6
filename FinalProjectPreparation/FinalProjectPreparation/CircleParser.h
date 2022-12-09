#pragma once
#include "IParsable.h"
#include "Object.h"
#include "Circle.h"
#include <string>
#include <vector>

class CircleParser : public IParsable
{
public:

private:

public:
	std::string toString();
	Object* parse(std::string str);
	std::string parserdObjectName();
};


