#ifndef _FRACTION_H
#define _FRACTION_H
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <tuple>
#include <regex>

class Fraction
{
private:
    int _tu_so;
    int _mau_so;

public:
    enum ParseErrorCode
    {
        EmptyInput,
        InvalidInputFormat,
        ZeroDenominator
    };
public:
    Fraction();
    Fraction(int tu, int mau);
    Fraction(const Fraction&);
    ~Fraction();
    Fraction operator+(const Fraction&);
    Fraction& operator=(const Fraction&);

public:
    int LayTu() {return _tu_so;};
    int LayMau() {return _mau_so;};
    static std::tuple<bool, Fraction, int> parse(std::string buffer);

    void print()
    {
        std::cout << _tu_so << "/" << _mau_so << std::endl;
    }

};




#endif