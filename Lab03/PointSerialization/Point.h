#ifndef _POINT_H
#define _POINT_H
#include <fstream>
#include <iostream>

class Point
{
private:
    int _x;
    int _y;
public:
    Point();
    Point(int x, int y);
    void print(){
        std::cout << _x << " " << _y << std::endl;
    }
    void WritePoint(std::ofstream &o);
};

#endif