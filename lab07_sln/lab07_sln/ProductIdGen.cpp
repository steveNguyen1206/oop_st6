#include "ProductIdGen.h"
#include <sstream>
#define MAX_ID 100

std::string ProductIdGenerator::next()
{
    int id = 0;
    std::string filename = "";
    do 
    {
        id++;
        std::stringstream builder;
        builder << _dbFolder << "\\" << id << ".txt";
        filename = builder.str();
    } while (std::filesystem::exists(filename));
   
    std::stringstream builder;
    builder << id;

    std::string result = builder.str();
   return result;
}

ProductIdGenerator::ProductIdGenerator()
{
}

ProductIdGenerator::ProductIdGenerator(std::string folder)
{
    _dbFolder = folder;
}