#pragma once
#include <vector>
#include <string>
#include "sstream"

namespace Utils {
    class String 
    {
        public:
            static
                std::vector<std::string> split(std::string str, std::string delim);
            static
                std::string trim(std::string str);
            static
                void ltrim(std::string &s);
            static
                void rtrim(std::string &s);
            static
                bool replace_first(std::string& s, std::string const& to_replace, std::string const& new_text);
            static
                void replace(std::string& s, std::string const& to_replace, std::string const& new_text);
    };
}
