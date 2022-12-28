#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <memory>
#include <vector>
#include "product.h"
#include "ProductIdGen.h"
#include "Utils.h"

class ProductDataset
{
private:
    std::string _dbFolder;
    std::shared_ptr<ProductIdGenerator> _idGen = NULL;
public:
    ProductDataset();
    ProductDataset(std::string folder);
public:
    std::shared_ptr<ProductIdGenerator> idGen();
    int add(const Product&p);
    std::vector<Product> getAll();
    static Product parse(std::string data);
};



