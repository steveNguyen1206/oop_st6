#include "RandomFractionGenerator.h"
#include <iostream>

Fraction RandomFractionGenerator::next()
{
    int tu_so, mau_so;
    tu_so = RandomIntegerGenerator::instance()->next();
    do
    {
        mau_so = RandomIntegerGenerator::instance()->next();
    } while (mau_so == 0);
    
    Fraction p(tu_so, mau_so);
    return p;
}

Fraction RandomFractionGenerator::next(int left, int right)
{
    int tu_so, mau_so;
    tu_so = RandomIntegerGenerator::instance()->next(left, right);
    do
    {
        mau_so = RandomIntegerGenerator::instance()->next(left, right);
    } while (mau_so == 0);
    
    return Fraction (tu_so, mau_so);
}