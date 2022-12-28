#include "Fraction.h"
#include "FractionFromKeyBoard.h"
#include <iostream>
#include "Pluralize.h"
#include <vector>
#include "RandomIntegerGenerator.h"
#include "Converters.h"


std::shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::_my_instance;

int main()
{
    std::cout << "Working with fractions from the keyboard";
    int n = RandomIntegerGenerator::instance()->next(5,10);
    std::cout << "Please enter " << Pluralize(n, "fraction", "fractions") << ". " << std::endl;
    std::vector<Fraction> fractions;
    GetVector(fractions, n, 1, 100);

    Fraction sum;
    for(int i = 0; i < fractions.size(); i++)
        sum = sum + fractions[i];
    
    FractionToLowestTermConverter flc;
    std::cout << "The sum of all entered fractions is: " << flc.convert(sum);
}