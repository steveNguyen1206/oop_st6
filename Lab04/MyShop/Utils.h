#ifndef _UTILS_H
#define _UTILS_H
#include <vector>
#include <string>
#include <iostream>
#include <tuple>
#include <cstdlib>
#include <regex>
#include "math.h"
#include <sstream>
#include <iomanip>

namespace Utils
{
    class String
    {
    public:
        static std::vector<std::string> split(std::string str, std::string delim);
        static int PriceToIntConverter(std::string str);
        static std::string IntToPriceConverter(int price);
        static std::string Pluralize(int n, std::string singular, std::string plural);
        
    };

}

#endif