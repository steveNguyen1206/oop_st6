#pragma once
#include "Object.h"
#include <string>

class IValueConverter
{
public:

private:

public:
	virtual std::string convert(Object*) = 0;
};

