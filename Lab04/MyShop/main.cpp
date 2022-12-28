#include <iostream>
#include <string>
#include <vector>
#include "Category.h"
#include "Utils.h"
#include <fstream>
#include "Parser.h"
#include "Product.h"
#include "Database.h"
#include "Queries.h"

inline bool exit(const std::string &name)
{
    std::ifstream f(name.c_str());
    return f.good();
}

std::vector<Product> Database::products;
std::vector<Category> Database::categories;

int main()
{

    if(exit("categories.txt"))
        Database::categories = Parser<Category>::readFile("categories.txt");
    else
        std::cerr << "File not found!";

    if(exit("products.txt"))
        Database::products = Parser<Product>::readFile("products.txt");
    else    
        std::cerr << "File not found!";

    std::cout << "My Shop" << std::endl;

    bool ShouldRepeat = true;
    int option;
    std::string keyWord;
    std::string lowPirce;
    std::string highPirce;
    std::vector<Product> query;
    do
    {
        ShouldRepeat = true;
        std::cout << std::endl << "What do you want to do?" << std::endl;  
        std::cout << "1. Display all categories" << std::endl;  
        std::cout << "2. Find products by name" << std::endl;  
        std::cout << "3. Find products by price range" << std::endl;
        std::cout << std::endl << "0. Quit" << std::endl;

        std::cout << std::endl << "Please enter your choice: " ;
        std::cin >> option;
        std::cout << std::endl;
        switch (option)
        {
        case 0:
            ShouldRepeat = false;
            break;
        case 1:
            std::cout<< "All categories: " << std::endl;
            for(int i = 0; i < Database::categories.size(); i++)
            {
                std::cout << i + 1 << ". " << Database::categories[i];
            }
            
            int cateID;
            std::cout << std::endl << "Enter a category id to see all products belong: ";
            std::cin >> cateID;
            query = GetProductByCategoryID(Database::products, cateID);
            std::cout << "Found " << Utils::String::Pluralize(query.size(), "result: ", "results: ") << std::endl;
            for(int i = 0; i < query.size(); i++)
            {
                std::cout << i + 1 << ". " << query[i];
            }
            std::getchar();
            break;
        case 2:
            std::cout << "Enter key word: ";
            std::getchar();
            std::getline(std::cin, keyWord);
            query = FindProductByKeyWord(Database::products, keyWord);
            std::cout << "Searching for \"" << keyWord << "\"." << std::endl;
            std::cout << "Found " << Utils::String::Pluralize(query.size(), "result: ", "results: ") << std::endl;
            for(int i = 0; i < query.size(); i++)
            {
                std::cout << i + 1 << ". " << query[i];
            }
            break;
        case 3:
            std::cout << "Enter a range of price in which you want to search (in price format): " << std::endl;
            std::cout << "Low price: ";
            std::cin >> lowPirce;
            std::cout << "High price: ";
            std::cin >> highPirce;
            query = FindProductInPriceRange(Database::products, lowPirce, highPirce);
            std::cout << "Searching for products within the price range of [" << lowPirce << ", " << highPirce << "]." << std::endl;
            std::cout << "Found " << Utils::String::Pluralize(query.size(), "result: ", "results: ") << std::endl;
            for(int i = 0; i < query.size(); i++)
            {
                std::cout << i + 1 << ". " << query[i];
            }
            std::getchar();
            break;
        default:
            break;
        }    

        if(option != 0)
        {
            std::cout << std::endl << "Press enter to continue";
            std::getchar();
        }
    } while (ShouldRepeat);
    


}