#pragma once
#include "product.h"
#include "SampleProduct.h"
#include "RandomIntegerGenerator.h"
#include "ProductIdGen.h"
#include <string>
#include <sstream>
#include <iostream>

class ProductGenerator
{
public:
    Product next(std::string id);
};

