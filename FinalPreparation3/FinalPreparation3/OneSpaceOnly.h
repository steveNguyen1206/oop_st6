#pragma once
#include "IRule.h"

class OneSpaceOnly : public IRule
{
public:

private:

public:
	std::string toString()
	{
		return "One space only";
	};

	std::string rename(std::string str)
	{
		return Utils::String::trim(str);
	};
};

