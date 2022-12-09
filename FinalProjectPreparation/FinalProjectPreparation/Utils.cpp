#include "Utils.h"

std::vector<std::string> Utils::String::split(std::string str, std::string delim)
{
    std::vector<std::string> result;
    size_t pos;
    while((pos = str.find(delim)) != std::string::npos)
    {
        std::string token;
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delim.length());
    }
    result.push_back(str);
    return result;
}
