#include "Point.h"


Point::Point()
{
    _x = 0;
    _y = 0;
}
Point::Point(int x, int y)
{
    _x = x;
    _y = y;
}

void Point::WritePoint(std::ofstream &o)
{
    if(o.is_open())
    {
        o << "(" << _x << ", " << _y << ")\n";
    }
}


