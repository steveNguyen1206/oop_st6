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

void Utils::String::ltrim(std::string &s)
{
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
}

void Utils::String::rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

std::string Utils::String::trim(std::string str)
{
    std::stringstream builder;
    size_t pos;
    std::string delim = " ";
    Utils::String::ltrim(str);
    while ((pos = str.find(delim)) != std::string::npos)
    {
        std::string token;
        token = str.substr(0, pos);
        builder << token << " ";
        str.erase(0, pos + delim.length());
        Utils::String::ltrim(str);
    }
    builder << str;
    std::string res = builder.str();
    Utils::String::rtrim(res);
    return res;
}

bool Utils::String::replace_first(std::string& s, std::string const& to_replace, std::string const& new_text) 
{
    std::size_t pos = s.find(to_replace);
    if (pos == std::string::npos) return false;
    s.replace(pos, to_replace.length(), new_text);
    return true;
}

void Utils::String::replace(std::string& s, std::string const& to_replace, std::string const& new_text)
{
    while (replace_first(s, to_replace, new_text)) {};
}

