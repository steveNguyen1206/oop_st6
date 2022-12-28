#include "Queries.h"

std::ostream& operator << (std::ostream& output, const Product& p)
{
    output << "Catogery: " << GetCategoryNameByID(Database::categories, p._categoryID) << ", ID: " << p._ID  << ", Name: " << p._name << ", Price: " << Utils::String::IntToPriceConverter(p._price) << " d" << std::endl;
    return output;
}

std::string GetCategoryNameByID(std::vector<Category> categories, int id)
{
    for(int i = 0; i < categories.size(); i++)
        if(categories[i]._ID == id)
            return categories[i]._name;

    return "Not exit category";
}

std::vector<Product> GetProductByCategoryID(std::vector<Product> products, int cateID)
{
    std::vector<Product> result;
    for(auto i : products)
    {
        if(i._categoryID == cateID)
            result.push_back(i);
    }
    return result;
}

std::vector<Product> FindProductByCategory(const Category&p)
{
    return GetProductByCategoryID(Database::products, p._ID);
}


std::vector<Product> FindProductByKeyWord(std::vector<Product> products, std::string key)
{
    std::string pattern = ".*" + key + ".*";
    std::vector<Product> result;
    for(auto i : products)
    {
        if(std::regex_match(i._name, std::regex(pattern, std::regex_constants::icase)))
            result.push_back(i);
    }
    return result;
}


std::vector<Product> FindProductInPriceRange(std::vector<Product> products, std::string low, std::string high)
{
    int lowInt = Utils::String::PriceToIntConverter(low);
    int highInt = Utils::String::PriceToIntConverter(high);
    std::vector<Product> result;

    for(auto i : products)
        if(i._price >= lowInt && i._price <= highInt)
            result.push_back(i);
    
    return result;
}
