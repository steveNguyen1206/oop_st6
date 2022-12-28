#include "fraction.h"

std::tuple<bool, int, Fraction> Fraction::parse(std::string buffer)
{
    bool success = true;
    int errorCode = 0;
    Fraction data;

    std::string pattern = "\\d+\\/\\d+";
    if(buffer.empty())
    {
        success = false;
        errorCode = Fraction::ErrorCode::InputEmpty;
    }
    else
    {
        bool match = std::regex_match(buffer, std::regex(pattern));
        if(!match)
        {
            success = false;
            errorCode = Fraction::ErrorCode::InvalidInput;
        }
        else
        {
            std::string delim = "/";
            std::vector<std::string> split = Utils::String::split(buffer, delim);
            int tuso = std::stoi(split[0]);
            int mauso = std::stoi(split[1]);
            data = Fraction(tuso, mauso);
        }
    }

    auto result = std::make_tuple(success, errorCode, data);
    return result;
}

std::ostream& operator << (std::ostream& output, const Fraction & p)
{
    output << p._tuso << "/" << p._mauso;
    return output;
}

std::string FractionToLowestTermConverter::conevert(const Fraction &p)
{
    int GCD = Utils::Integer::gcd(p._tuso, p._mauso);
    Fraction tmp = Fraction(p._tuso / GCD, p._mauso / GCD);

    std::stringstream builder;

    if(tmp._tuso % tmp._mauso == 0)
        builder << tmp._tuso / tmp._mauso;
    else if(tmp._tuso > tmp._mauso)
        builder << tmp._tuso / tmp._mauso << " " << tmp._tuso % tmp._mauso << "/" << tmp._mauso;
    else
        builder << tmp._tuso << "/" << tmp._mauso;
    
    std::string result = builder.str();
    return result;

}
