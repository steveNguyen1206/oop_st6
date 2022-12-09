#pragma once
#include "IParsable.h"
#include "DailyEmployee.h"

class DailyEmployeeParser : public IParsable
{
public:

private:

public:
	std::string toString();
	Object* parse(std::string str);
	std::string parserdObjectName();
};

