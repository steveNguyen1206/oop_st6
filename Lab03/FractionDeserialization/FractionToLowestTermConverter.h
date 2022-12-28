#ifndef _FRACTION_CONVERTER_H
#define _FRACTION_CONVERTER_H
#include "Fraction.h"
#include <string>


class FractionToLowestTermConverter
{
public:
    std::string convert(Fraction f);
    Fraction convertBack(const std::string& str);
};


#endif