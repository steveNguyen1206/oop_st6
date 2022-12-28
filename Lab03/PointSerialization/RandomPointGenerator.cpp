#include "RandomPoinGenerator.h"

Point RandomPointGenerator::next()
{
    int x = RandomIntegerGenerator::instance()->next();
    int y = RandomIntegerGenerator::instance()->next();

    Point res(x, y);
    return res;
}
Point RandomPointGenerator::next(int left, int right)
{
    int x = RandomIntegerGenerator::instance()->next(left, right);
    int y = RandomIntegerGenerator::instance()->next(left, right);

    Point res(x, y);
    return res;
}