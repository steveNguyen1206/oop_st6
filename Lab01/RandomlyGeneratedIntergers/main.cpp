#include "RandomlyGeneratedIntergers.h"

int main()
{
    std::vector<int> numbers;
    int n;
    srand(time(NULL));
    std::cout << "Working with randomly generated integers: " << std::endl;
    GetVetor(numbers, n, 5, 10, 10, 100);
    FindSubVector(numbers, "odd", isOdd);
    FindSubVector(numbers, "even", isEven);
    FindSubVector(numbers, "palindromic", isPalindromic);
    FindSubVector(numbers, "prime", isPrime);  

}