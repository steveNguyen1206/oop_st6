#pragma once
#include <vector>
#include <string>

namespace Utils {
    class String 
    {
        public:
            static
                std::vector<std::string> split(std::string str, std::string delim);
    };
}
