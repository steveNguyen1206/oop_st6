#pragma once
#include "IParsable.h"
#include "OneSpaceOnly.h"

class OneSpaceOnlyParser : public IParsable
{
public:

private:

public:
	std::string toString()
	{
		return "One space only parser";
	};

	Object* parse(std::string str)
	{
		Object* p = new OneSpaceOnly();
		return p;
	}

	std::string parserdObjectName()
	{
		return "OneSpaceOnly";
	}

};
