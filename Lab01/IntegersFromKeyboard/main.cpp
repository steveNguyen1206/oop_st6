#include "IntegersFromKeyboard.h"


int main()
{
    std::cout << "Working with interger arrays from the keyboard." << std::endl;

    std::vector <int> numbers;
    int n;
    BuildDynamicArray(numbers, n);
    
    FindSubVector(numbers, "odd", isOdd);
    FindSubVector(numbers, "even", isEven);
    FindSubVector(numbers, "palindromic", isPalindromic);
    FindSubVector(numbers, "prime", isPrime);

}
