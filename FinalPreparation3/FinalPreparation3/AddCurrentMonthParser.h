#pragma once
#include "IParsable.h"
#include "AddCurrentMonth.h"

class AddCurrentMonthParser : public IParsable
{
public:

private:

public:
	std::string toString()
	{
		return "Add current month parser";
	};

	Object* parse(std::string str)
	{
		Object* p = new AddCurrentMonth();
		return p;
	}

	std::string parserdObjectName()
	{
		return "AddCurrentMonth";
	}

};
