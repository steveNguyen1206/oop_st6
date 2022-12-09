#pragma once
#include "IParsable.h"
#include "Object.h"
#include "Square.h"
#include <string>
#include <vector>

class SquareParser : public IParsable
{
public:

private:

public:
	std::string toString();
	Object* parse(std::string str);
	std::string parserdObjectName();
};


