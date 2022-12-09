#pragma once
#include "Object.h"
#include "IValueConverter.h"
#include "Integer.h"
#include "NumberInformation.h"
#include <sstream>
#include <string>

class IntegerToCurrencyConverter : IValueConverter
{
public:
	std::string convert(Object*);
	std::string toString() { return "Integer to currency converter."; };
private:
};

