#pragma once
#include "IParsable.h"
#include "Object.h"
#include "Rectangle.h"
#include <string>
#include <vector>

class RectangleParser : public IParsable
{
public:

private:

public:
	std::string toString();
	Object* parse(std::string str);
	std::string parserdObjectName();
};


