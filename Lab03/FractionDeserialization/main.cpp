#include <iostream>
#include <fstream>
#include "Fraction.h"
#include "FractionToLowestTermConverter.h"
#include "Pluralize.h"
#include <string>
#include <vector>
#include <tuple>

struct
{
    std::vector<Fraction> fractions;
} state;

inline bool exists(const std::string &name)
{
    std::ifstream f(name.c_str());
    return f.good();
}

int main()
{
    std::cout << "Fraction deserialization" << std::endl;

    std::cout << std::endl;
    std::cout << "Reading fractions from data.txt file...";
    std::ifstream reader;

    if (exists("data.txt"))
    {
        reader.open("data.txt", std::ios::in);
        int n;
        std::string buffer;
        std::getline(reader, buffer);
        n = stoi(buffer);
        int i = 0;
        do
        {
            bool succees;
            Fraction data;
            int errorCode;
            std::getline(reader, buffer);
            std::tie(succees, data, errorCode) = Fraction::parse(buffer);
            if(succees)
            {
                state.fractions.push_back(data);
            }
            i++;
        } while (i < n);

            // for(int i = 0; i < fractions.size(); i++)
            //     fractions[i].print();
        std::cout << "\nFound " << Pluralize(state.fractions.size(), "fraction", "fractions") << ": ";

        FractionToLowestTermConverter flc;
        std::cout << flc.convert(state.fractions[0]);

        for(int i = 1; i < state.fractions.size(); i++)
            std::cout << ", " << flc.convert(state.fractions[i]);
        
        Fraction sum;
        for(int i = 0; i < state.fractions.size(); i++)
            sum = sum + state.fractions[i];

        std::cout << "\nThe sum of all fractions is: " << flc.convert(sum);

        reader.close();
    }
    else
    {
        std::cout << "\nFile not found." << std::endl;
        std::cout << "Exitting the program.";
    }
}