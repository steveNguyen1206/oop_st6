#pragma once
#include <vector>
#include <string>
#include <sstream>

class Product
{
private:
    std::string _id;
    std::string _name;
    int _price;
public:
    Product(std::string name, int price, std::string id);
public:
    std::string toString() const;
    std::string id() const;

};
