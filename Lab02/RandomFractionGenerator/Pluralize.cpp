#include "Pluralize.h"


std::string Pluralize(int n, std::string singular, std::string plural)
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
