#ifndef _PARSER_H
#define _PARSER_H
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <cstdlib>

template <class T>
class Parser
{
public:
    static std::vector<T> readFile(std::string fileName)
    {
        std::ifstream reader;
        reader.open(fileName, std::ios::in);

        bool success;
        int errorCode;
        T data;
        std::vector<T> result;
        std::string buffer;
        do
        {
            std::getline(reader, buffer);
            std::tie(success, data, errorCode) = T::parse(buffer);
            if (success)
                result.push_back(data);
        } while (!reader.eof());

        return result;
    }
};

#endif
