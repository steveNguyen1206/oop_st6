#include "Category.h"


Category::Category(int id, std::string name)
{
    _ID = id;
    _name = name;
}   

Category& Category::operator = (const Category& p)
{
    _ID = p._ID;
    _name = p._name;
}


Category::~Category()
{
}

std::ostream& operator << (std::ostream& output, const Category& p)
{
    output << "Category: " << p._name << ", ID: " << p._ID << std::endl;
    return output;
}


std::tuple<bool, Category, int> Category::parse(std::string str)
{
    bool success = true;
    int errorCode = 0;
    int id = -1;
    std::string name = "";
    Category data;

    if(str.empty())
    {
        success = false;
        errorCode = Category::ParserErrorCode::EmptyInput;
    }
    else
    {
        std::string delim = ": ";
        std::vector<std::string> split = Utils::String::split(str, delim);
        if (split.size() != 2)
        {
            success = false;
            errorCode = Category::ParserErrorCode::WrongInput;
        }
        else
        {
            str = split[1];
            delim = ", ";

            split = Utils::String::split(str, delim);
            if (split.size() != 2)
            {
                success = false;
                errorCode = Category::ParserErrorCode::WrongInput;
            }
            else
            {
                delim = "=";
                id = std::stoi(Utils::String::split(split[0], delim)[1]);
                name = Utils::String::split(split[1], delim)[1];
                data = Category(id, name);
            }

        }
    }
    auto result = std::make_tuple(success, data ,errorCode);
    return result;
}


