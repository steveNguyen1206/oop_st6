#include "RandomIntegerGenerator.h"

int RandomIntegerGenerator::next()
{
    return rand();
}
int RandomIntegerGenerator::next(int left, int right)
{
    return (rand() % (right - left + 1) + left);
}
int RandomIntegerGenerator::next(int ceiling)
{   
    return( rand() % ceiling);
}   