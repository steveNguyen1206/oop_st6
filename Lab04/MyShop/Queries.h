#ifndef _QUERIES_H
#define _QUERIES_H
#include "Database.h"
#include "Category.h"
#include "Utils.h"
#include "Product.h"
#include <iostream>
#include <regex>

std::ostream& operator << (std::ostream& output, const Product& p);
std::string GetCategoryNameByID(std::vector<Category> categories, int id);
std::vector<Product> GetProductByCategory(std::vector<Product> products, int cateID);
std::vector<Product> FindProductByKeyWord(std::vector<Product> products, std::string key);
std::vector<Product> FindProductInPriceRange(std::vector<Product> products, std::string low, std::string high);
std::vector<Product> FindProductByCategory(const Category&p);

#endif