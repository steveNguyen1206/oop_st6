#ifndef _CONVERTERS_H
#define _CONVERTERS_H
#include "Fraction.h"
#include "Integer.h"
#include <string>
#include <sstream>
#include <iomanip>


typedef void* Object;

class FractionToStringConverter
{
public:
    std::string convert( Fraction f);
};

class FractionToLowestTermConverter
{
public:
    std::string convert( Fraction f);
};

class FractionToPercentageConverter
{
public:
    std::string convert( Fraction f);
};

class FractionToDecimalConverter
{
public:
    std::string convert( Fraction f);
};

#endif