#ifndef  _PRODEUCT_H
#define _PRODEUCT_H
#include <string>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include <cstdlib>
#include <tuple>
#include <vector>
#include "Database.h"

class Product
{
private:
    int _ID;
    std::string _name;
    int _price;
    int _categoryID;
public:
    Product()
    {
        _ID = -1;
        _name = "";
        _price = 0;
        _categoryID = -1;
    }
    Product(int id, std::string name, int price, int cateID);
    Product(const Product&p)
    {
        _ID = p._ID;
        _name = p._name;
        _price = p._price;
        _categoryID = p._categoryID;
    }
    Product& operator = (const Product& p);
    ~Product();
    enum ParserErrorCode{
        EmptyInput,
        WrongInput
    };

public:
    static std::tuple<bool, Product, int> parse(std::string str);
    friend std::ostream& operator << (std::ostream& output, const Product& p);
    friend std::vector<Product> GetProductByCategoryID(std::vector<Product> products, int cateID);
    friend std::vector<Product> FindProductByKeyWord(std::vector<Product> products, std::string key);
    friend std::vector<Product> FindProductInPriceRange(std::vector<Product> products, std::string low, std::string high);

     
};




#endif