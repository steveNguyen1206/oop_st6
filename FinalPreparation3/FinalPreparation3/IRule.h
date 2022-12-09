#pragma once
#include "Object.h"
#include <vector>
#include <string>
#include <sstream>
#include "Utils.h"

class IRule : public Object
{
public:

private:

public:
	virtual std::string rename(std::string str) = 0;
};

