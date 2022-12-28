#ifndef _RANDOM_FRACTION_GENERATOR_H
#define _RANDOM_FRACTION_GENERATOR_H
#include "Fraction.h"
#include "RandomIntegerGenerator.h"

class RandomFractionGenerator
{
public:
    Fraction next();
    Fraction next(int left, int right);
};


#endif