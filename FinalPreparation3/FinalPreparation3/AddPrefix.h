#pragma once
#include "IRule.h"

class AddPrefix : public IRule
{
private:
	std::string _prefix;
public:
	AddPrefix(std::string prefix)
	{
		_prefix = prefix;
	};
public:
	std::string toString()
	{
		return "Add prefix";
	};

	std::string rename(std::string str)
	{
		std::stringstream builder;
		builder << _prefix << " " << str;
		std::string res = builder.str();
		return res;
	};
};

