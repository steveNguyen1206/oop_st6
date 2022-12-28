#include "Utils.h"


std::vector<std::string> Utils::String::split(std::string str, std::string delim)
    {
        std::vector<std::string> out;
        std::string token;
        size_t pos = 0;

        while ((pos = str.find(delim)) != std::string::npos)
        {
            token = str.substr(0, pos);
            out.push_back(token);
            str.erase(0, pos + delim.length());
        }

        out.push_back(str);

        return out;
    }

int Utils::String::PriceToIntConverter(std::string str)
{
    int res = 0;
    std::string delim = ".";
    std::vector<std::string> split = Utils::String::split(str, delim);
    int n = split.size();
    for(int i = 0; i < n; i++)
    {
        int k = (n - i - 1) * 3;
        res += std::stoi(split[i]) * pow(10, k);
    }
    return res;
}


std::string Utils::String::IntToPriceConverter(int price)
{
    std::stringstream builder;
    std::vector<int> stack;
    do
    {
        stack.push_back(price % 1000);
        price /= 1000;
    } while (price != 0);

    builder << std::to_string(stack.back());
    stack.pop_back();
    while(!stack.empty())
    {
        builder << ".";
        builder << std::setw(3) << std::setfill('0') << std::to_string(stack.back());
        stack.pop_back();
    }

    std::string result = builder.str();
    return result;
    
}

std::string Utils::String::Pluralize(int n, std::string singular, std::string plural)
{
    std::stringstream builder;
    builder << n << " ";
    if(n < 2)
    {
        builder << singular;
    }
    else
    {
        builder << plural;
    }

    std::string result = builder.str();
    return result;
}
