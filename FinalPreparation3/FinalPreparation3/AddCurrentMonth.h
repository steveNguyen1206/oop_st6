#pragma once
#include "IRule.h"
#include <iomanip>
#include <iostream>

class AddCurrentMonth : public IRule
{
public:
	static int month;
	static int date;
private:

public:
	std::string toString()
	{
		return "Add current month";
	};

	std::string rename(std::string str)
	{
		std::stringstream builder;
		builder  << month << std::setfill('0') << std::setw(2) << date << " " << str;
		std::string res = builder.str();
		return res;
	};
};

