#include "RandomlyGeneratedIntergers.h"
#include <cstdlib>


void GetVetor(std::vector<int> &numbers, int &n, int min_n, int max_n, int min_int, int max_int)
{
    n = rand() % (max_n - min_n + 1) + min_n ;
    std::cout << "Generating " << Pluralize(n, "integer", "integers") <<": ";
    for(int i = 0; i< n; i++)
    {
        numbers.push_back(rand() % (max_int - min_int + 1) + min_int);
    }
    std::cout << numbers[0];
    for(int i = 1; i < n; i++)
        std::cout << ", " << numbers[i];
    std::cout << std::endl;    
    
}

std::string Pluralize(int count, std::string singular, std::string plural)
{
    std::stringstream builder;
    
    builder << count << " ";
    if(count <= 1)
    {
        builder << singular;
    }
    else
    {
        builder << plural;
    }

    std::string result = builder.str();
    return result;
}

bool isOdd(int number) 
{
    return (number % 2) != 0;
}

bool isEven(int number)
{
    return !isOdd(number);
}

bool isPalindromic (int number)
{
    std::string num_str = std::to_string(number);
    int len = num_str.length();
    if (len < 2) 
        return false;
    int i = 0;
    while(i < len/2)
    {
        if ( num_str.at(i) != num_str.at(len - i - 1) )
            return false;
        i++;
    }
    return true;
}

bool isPrime(int number)
{
    if( number < 2 )
        return false;
    int k = sqrt(number);
    for(int i = 2; i <= k; i++ )
        if(number % i == 0)
            return false;
    return true;
}

std::vector<int> Reduce(std::vector<int> numbers, Predicate sastify)
{
    std::vector<int> result;
    for(int i = 0; i < numbers.size(); i++)
    {
        if(sastify(numbers[i]))
            result.push_back(numbers[i]);
    }

    return result;
}

void FindSubVector(std::vector<int> numbers, std::string condition, Predicate sastify)
{
    std::vector<int> subVec = Reduce(numbers, sastify);
    std::cout << "Found " << Pluralize(subVec.size(), condition + " number", condition + " numbers");
    if(!subVec.empty())
    {
        std::cout << ": "<< subVec[0];
    }
    for(int i = 1; i < subVec.size(); i++)
        std::cout << ", " << subVec[i];
    std::cout << std::endl; 
}



