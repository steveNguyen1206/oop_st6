#pragma once
#include "IParsable.h"
#include "AddPrefix.h"

class AddPrefixParser : public IParsable
{
public:

private:

public:
	std::string toString()
	{
		return "Add prefix parser";
	};

	Object* parse(std::string str)
	{
		Object* p = new AddPrefix(str);
		return p;
	}

	std::string parserdObjectName()
	{
		return "AddPrefix";
	}

};
