#ifndef _FRACTION_H
#define _FRACTION_H
#include <tuple>
#include <regex>
#include <string>
#include "Utils.h"
#include <iostream>
#include <sstream>
class Fraction;

class FractionToLowestTermConverter
{
    public:
        static std::string conevert(const Fraction &p);
};

class Fraction
{
private:
    int _tuso;
    int _mauso;

public:
    enum ErrorCode{
        InputEmpty,
        InvalidInput,
        DenominatorZero
    };
public:
    Fraction(){_tuso = 0; _mauso = 1;}
    Fraction(int x, int y){
        if(y != 0) {_mauso = y; _tuso = x;} 
        else {_tuso = 0; _mauso = 1;};
    }
    Fraction(const Fraction &p) {_tuso = p._tuso; _mauso = p._mauso;}
    Fraction& operator = (const Fraction &p){ _tuso = p._tuso; _mauso = p._mauso; return *this;}
    ~Fraction(){};
    static std::tuple<bool, int, Fraction> parse(std::string buffer);

    friend std::ostream& operator << (std::ostream& output, const Fraction & p);
    friend std::string FractionToLowestTermConverter::conevert(const Fraction &p);
};




#endif