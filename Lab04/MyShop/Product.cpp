#include "Product.h"



Product::Product(int id, std::string name, int price, int catId)
{
    _ID = id;
    _name = name;
    _price = price;
    _categoryID = catId;
}   

Product& Product::operator = (const Product& p)
{
    _ID = p._ID;
    _name = p._name;
    _price = p._price;
    _categoryID = p._categoryID;
}


Product::~Product()
{
}


std::tuple<bool, Product, int> Product::parse(std::string str)
{
    bool success = true;
    int errorCode = 0;
    int id = -1;
    std::string name = "";
    int price;
    int cateID;
    Product data;

    if(str.empty())
    {
        success = false;
        errorCode = Product::ParserErrorCode::EmptyInput;
    }
    else
    {
        std::string delim = "Product: ";
        std::vector<std::string> split = Utils::String::split(str, delim);
        if (split.size() != 2)
        {
            success = false;
            errorCode = Product::ParserErrorCode::WrongInput;
        }
        else
        {
            str = split[1];
            delim = ", ";

            split = Utils::String::split(str, delim);
            if (split.size() != 4)
            {
                success = false;
                errorCode = Product::ParserErrorCode::WrongInput;
            }
            else
            {
                delim = "=";
                id = std::stoi(Utils::String::split(split[0], delim)[1]);
                name = Utils::String::split(split[1], delim)[1];
                price = Utils::String::PriceToIntConverter(Utils::String::split(split[2], delim)[1]);
                cateID = std::stoi(Utils::String::split(split[3], delim)[1]);
                data = Product(id, name, price, cateID);
            }

        }
    }
    auto result = std::make_tuple(success, data ,errorCode);
    return result;
}

