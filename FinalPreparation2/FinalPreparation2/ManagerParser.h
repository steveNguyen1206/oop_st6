#pragma once
#include "IParsable.h"
#include "Manager.h"

class ManagerParser : IParsable
{
public:

private:

public:
	std::string toString();
	Object* parse(std::string str);
	std::string parserdObjectName();
};

