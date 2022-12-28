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

bool isInRange(int x, int left, int right)
{
    return (left <= x && right >= x);
}

std::tuple<bool, Fraction, int> Fraction::parse(std::string buffer)
{
    bool _success = true;
    Fraction _data;
    int _errorCode = 0;

    if(buffer.empty())
    {
        _success = false;
        _errorCode = Fraction::ParseErrorCode::EmptyInput;
    }
    else
    {
        std::string pattern = "\\d+\\/\\d+"; //regular expresstion for only fraction format 
        bool matched = std::regex_match(buffer, std::regex(pattern));
        if(!matched)
        {
            _success = false;
            _errorCode = Fraction::ParseErrorCode::InvalidInputFormat;
        }
        else
        {
            std::string split = "/";
            int position = buffer.find(split);
            int numerator = stoi(buffer.substr(0, position));
            int denominator = stoi(buffer.substr(position + split.length(), buffer.length() - position - split.length()));

            if(denominator == 0)
            {
                _success = false;
                _errorCode = Fraction::ParseErrorCode::ZeroDenominator;
            }
            else
            {
                _data = Fraction(numerator, denominator);
            }
        }
    }

    auto result = std::make_tuple(_success, _data, _errorCode);
    return result;

}
Fraction& Fraction::operator=(const Fraction&p)
{
    _tu_so = p._tu_so;
    _mau_so = p._mau_so;
    return *this;
}

Fraction Fraction::operator + (const Fraction&p)
{
    Fraction result(_tu_so * p._mau_so + p._tu_so*_mau_so, _mau_so*p._mau_so);
    return result;
}