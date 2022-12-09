#pragma once
#include "IParsable.h"
#include "RemoveSpecialChars.h"

class RemoveSpecialCharsParser : public IParsable
{
public:

private:

public:
	std::string toString()
	{
		return "Remove Special Chars Parser";
	};

	Object* parse(std::string str)
	{
		Object* p = new RemoveSpecialChars(str);
		return p;
	}

	std::string parserdObjectName()
	{
		return "RemoveSpecialChars";
	}

};
