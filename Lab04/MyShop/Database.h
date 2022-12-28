#ifndef _DATABASE_H
#define _DATABASE_H
#include <vector>
#include <string>

class Category;
class Product;

class Database
{
public:
    static std::vector<Category> categories; 
    static std::vector<Product> products; 
};

#endif