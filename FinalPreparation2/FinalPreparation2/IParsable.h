#pragma once
#include "Object.h"
#include "Utils.h"
#include <string>

class IParsable : public Object
{
private:

public:

	virtual	Object* parse(std::string str) = 0;
	virtual std::string parserdObjectName() = 0;

};



