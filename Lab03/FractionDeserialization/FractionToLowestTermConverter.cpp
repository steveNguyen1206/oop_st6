#include "FractionToLowestTermConverter.h"
#include <iostream>
#include <sstream>
#include "Integer.h"

std::string FractionToLowestTermConverter::convert(Fraction f)
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

Fraction FractionToLowestTermConverter::convertBack(const std::string &str)
{
    int tu_so, mau_so;
    std::stringstream builder;
    std::string frac = "/";
    size_t found = str.find(frac);
    if(found == 0)
    {
        tu_so = 1;
        mau_so = stoi(str.substr(1, str.length() - 1));
    }
    else if(found == str.length() - 1 )
    {
        tu_so = stoi(str.substr(0, found));
        mau_so = 1;
    }
    else
    {
        tu_so = stoi(str.substr(0, found));
        mau_so = stoi(str.substr(found + 1,str.length() - found -1));
    }
    return Fraction(tu_so, mau_so);

}
