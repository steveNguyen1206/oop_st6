#include "Fraction.h"

Fraction::Fraction()
{
    _tu_so = 0;
    _mau_so = 1;
    
}

Fraction::Fraction(int tu, int mau)
{
    _tu_so = tu;
    _mau_so = mau;
    
}


Fraction::Fraction(const Fraction& p)
{
    _tu_so = p._tu_so;
    _mau_so = p._mau_so;
}

Fraction::~Fraction()
{

}

Fraction& Fraction::operator=(const Fraction& p)
{
    this->_tu_so = p._tu_so;
    this->_mau_so = p._mau_so;
    return *this;
}