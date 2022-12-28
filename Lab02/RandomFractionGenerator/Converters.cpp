#include "Converters.h"
#include <iostream>


std::string FractionToStringConverter::convert( Fraction f)
{
    std::stringstream builder;
    if(f.LayTu() == 0 || f.LayMau() == 1)
        builder << f.LayTu();
    else builder << f.LayTu() << "/" << f.LayMau();
    std::string result = builder.str();
    return result;
}

std::string FractionToLowestTermConverter::convert( Fraction f)
{
    int gcd = Integer::FindGcd(f.LayTu(), f.LayMau());

    if(gcd != 1)
        f =  Fraction(f.LayTu() / gcd, f.LayMau() /gcd);

    std::stringstream builder;
    if(f.LayTu() < f.LayMau())
    {
        builder << f.LayTu() << "/" << f.LayMau();
    }
    else if((f.LayTu() % f.LayMau()) == 0)
    {
        builder << f.LayTu() / f.LayMau();
    }
    else
    {
        builder << f.LayTu() / f.LayMau() << " " << f.LayTu() % f.LayMau() << "/" << f.LayMau(); 
    }

    std::string result = builder.str();

    return result;
}

std::string FractionToPercentageConverter::convert( Fraction f)
{
    float per = ((float)f.LayTu()) / f.LayMau() * 100;
    std::stringstream builder;
    builder << std::fixed << std::setprecision(2) << per << "%";
    std::string result = builder.str();
    return result; 
}

std::string FractionToDecimalConverter::convert( Fraction f)
{
    float decimal = ((float)f.LayTu()) / f.LayMau();
    std::stringstream builder;
    builder << std::fixed << std::setprecision(3) << decimal;
    std::string result = builder.str();
    return result; 
}