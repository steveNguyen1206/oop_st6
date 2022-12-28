#include <iostream>
#include "fraction.h"
#include "Utils.h"
#include "dynamicArray.h"
#include <fstream>

inline bool exists(const std::string &name)
{
    std::ifstream f(name.c_str());
    return f.good();
}

int main()
{

    std::cout << "Working with dynamic array of fractions from file" << std::endl;
    std::string fileName = "fraction.txt";
    std::cout << "\nReading input: " << fileName << std::endl;

    DynamicArray<Fraction> myArray;

    std::string buffer;
    std::ifstream f;
    int n;
    if(!exists(fileName))
    {
        std::cerr << "File not found.";
        exit(1);
    }
    else
    {
        
        bool success;
        int errorCode;
        Fraction data;

        f.open(fileName);
        std::getline(f, buffer);
        n = std::stoi(buffer);
        std::cout << "Expecting to have " << Utils::String::Pluralize(n, "fraction", "fractions") << std::endl;
        for(int i = 0; i < n; i++)
        {
            std::getline(f, buffer);
            std::tie(success, errorCode, data) = Fraction::parse(buffer);
            if(success)
                myArray.push_back(data);
        }
        f.close();


        std::cout << "\nFound " << Utils::String::Pluralize(myArray.Size(), "fraction", "fractions") << ": ";
        FractionToLowestTermConverter flc;
        if(myArray.Size() > 0)
            std::cout << flc.conevert(myArray[0]);
        for(int i = 1; i < myArray.Size(); i++)
            std::cout << ", " << flc.conevert(myArray[i]);
    }



}