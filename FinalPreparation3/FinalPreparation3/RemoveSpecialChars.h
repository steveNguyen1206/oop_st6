#pragma once
#include "IRule.h"

class RemoveSpecialChars : public IRule
{
public:
	RemoveSpecialChars(std::string str)
	{
		int pos = str.find("=") + 1;
		str = str.substr(pos, str.length() - pos);
		for (int i = 0; i < str.length(); i++)
		{
			std::string tmp = str.substr(i, 1);
			_blackList.push_back(tmp);
		}
	}
	
private:
	std::vector<std::string> _blackList;
public:
	std::string toString()
	{
		return "Remove special characters";
	};

	std::string rename(std::string str)
	{
		for (auto to_replace : _blackList)
		{
			Utils::String::replace(str, to_replace, "");
		}
		return str;
	};
};

