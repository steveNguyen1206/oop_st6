#include "RandomIntegerGenerator.h"
#include <iostream>

int RandomIntegerGenerator::next()
{
    return rand();
}

int RandomIntegerGenerator::next(int ceilling)
{
    return (rand() % ceilling);
}

int RandomIntegerGenerator::next(int left, int right)
{
    int t = rand();
    t  = t % (right - left + 1) + left;
    // std::cout << t << std::endl;
    return t;
}