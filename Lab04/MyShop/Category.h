#ifndef  _CATEGORY_H
#define _CATEGORY_H
#include <string>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include <cstdlib>
#include <tuple>
#include <vector>

class Product;

class Category
{
private:
    int _ID;
    std::string _name;
public:
    Category()
    {
        _ID = -1;
        _name = "";
    }
    Category(int id, std::string name);
    Category(const Category&p)
    {
        _ID = p._ID;
        _name = p._name;
    }
    Category& operator = (const Category& p);
    ~Category();
    enum ParserErrorCode{
        EmptyInput,
        WrongInput
    };

public:
    static std::tuple<bool, Category, int> parse(std::string str);
    friend std::ostream& operator << (std::ostream& output, const Category& p);
    friend std::string GetCategoryNameByID(std::vector<Category> categories, int id);
    friend std::vector<Product> FindProductByCategory(const Category&p);


};




#endif