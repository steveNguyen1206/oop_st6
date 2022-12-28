// #include ".\MyShop\Utils.h"
#include <iostream>
#include <string>
// #include <vector>
// #include <tuple>
// #include <cstdlib>
// #include "test2.h"
// #include "test3.h"
#include <regex>

int main()
{
    std::string pattern = ".*mac.*";
    std::string buffer = "Macbook Pro";
    bool match = std::regex_match(buffer, std::regex(pattern, std::regex_constants::icase));
    if(match) std::cout << "yes";
}