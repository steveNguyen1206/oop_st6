#ifndef _FRACTION_FROM_KEYBOARD_H
#define _FRACTION_FROM_KEYBOARD_H
#include "Fraction.h"
#include <tuple>
#include <regex>
#include <string>
#include <vector>

class KeyBoradFraction: public Fraction
{
public:
    enum ParseErrorCode
    {
        EmptyInput,
        InvalidInputFormat,
        ZeroDenominator,
        ValueNotInDomain
    };
public:
    static std::tuple<bool, Fraction, int, std::string> parse(std::string buffer, int left, int right);
};

void GetVector(std::vector<Fraction> &fractions, int n, int left, int right);


#endif 