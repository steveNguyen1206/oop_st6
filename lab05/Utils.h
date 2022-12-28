#ifndef _UTILS_H
#define _UTILS_H
#include <string>
#include <sstream>
#include <vector>

namespace Utils {
    class String {
        public:
            static std::vector<std::string> split (std::string str, std::string delim)
            {
                std::vector<std::string> out;
                size_t pos = 0;
                std::string token;

                while((pos = str.find(delim)) != std::string::npos)
                {
                    token = str.substr(0, pos);
                    out.push_back(token);
                    str.erase(0, pos + delim.length());
                }

                out.push_back(str);

                return out;
            }

        static std::string Pluralize(int n, std::string singular, std::string plural)
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

    };

    class Integer {
        public:
            static int gcd(int a, int b)
            {
                if(b == 0) return a;
                else return gcd(b, a % b);
            }
    };
}

#endif