#ifndef _FRACTION_H
#define _FRACTION_H
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

class Fraction
{
private:
    int _tu_so;
    int _mau_so;
public:
    Fraction();
    Fraction(int tu, int mau);
    Fraction(const Fraction&);
    ~Fraction();

public:
    Fraction& operator = (const Fraction&);
    Fraction operator + (const Fraction&);
    int LayTu() {return _tu_so;};
    int LayMau() {return _mau_so;};
    void print()
    {
        std::cout << _tu_so << "/" << _mau_so << std::endl;
    }

};




#endif