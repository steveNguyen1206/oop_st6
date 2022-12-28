#include "product.h"



Product::Product( std::string name, int price, std::string id)
{
    _id = id;
    _name = name;
    _price = price;
}

std::string Product::toString() const
{
    std::stringstream builder;
    builder << "ID=" << _id << ", Name=" << _name << ", Price=" << _price;
    std::string result = builder.str();
    return result;
}

std::string Product::id() const
{
    return _id;
}

