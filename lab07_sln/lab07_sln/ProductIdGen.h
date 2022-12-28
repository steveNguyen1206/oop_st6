#pragma once
#include "product.h"
#include <string>
#include <filesystem>
#include "RandomIntegerGenerator.h"
#include "Utils.h"

class ProductIdGenerator
{
private:
    std::string _dbFolder;
public:
    ProductIdGenerator();
    ProductIdGenerator(std::string folder);
    std::string next();
};

