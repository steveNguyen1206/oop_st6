#ifndef _RANDOM_POINT_GENERATOR_H
#define _RANDOM_POINT_GENERATOR_H
#include "Point.h"
#include "RandomIntegerGenerator.h"

class RandomPointGenerator
{
public:
    Point next();
    Point next(int, int );
};

#endif