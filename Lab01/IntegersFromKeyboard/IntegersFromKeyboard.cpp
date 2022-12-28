#include "IntegersFromKeyboard.h"

bool success;
int data;
int errorCode;
std::string message;

//return success, data, error code, error message
std::tuple<bool, int, int, std::string> parse(int minRange, int maxRange) 
{
    std::string buffer;
    getline(std::cin, buffer);

    bool _success = true;
    int _data = 0;
    int _errorCode = 0;
    int tmp = 0;
    std::string _message = "";

    if(buffer.empty())
    {
        _success = false;
        _errorCode = IntergerParseErrorCode::EmptyInput;
        _message = "Input cannot be empty.";
    }
    else
    {
        std::string pattern = "\\d+"; //regular expresion for only digits
        bool matched = std::regex_match(buffer, std::regex(pattern));
        if(!matched)
        {
            _success = false;
            _errorCode = IntergerParseErrorCode::InvalidFormat;
            _message = "Invalid input format.";
        }
        else
        {
            tmp = stoi(buffer);
            if(tmp < minRange || tmp > maxRange)
            {
                _success = false;
                _errorCode = IntergerParseErrorCode::ValueNotInDomain;
                _message = "The interger must ne in the range of [" + std::to_string(minRange) + ", " + std::to_string(maxRange) + "].";
            }
        }
    }


    if(_success)
    {
        _data = tmp;
    }

    auto result = make_tuple(_success, _data, _errorCode, _message);
    return result;
}

void GetN(int &n, int minN, int maxN)
{
    bool shouldRepeat = false;
    do
    {
        shouldRepeat = false;
        std::cout << "Please enter an interger from the range of [" << minN << ", " << maxN << "]: ";
        tie(success, data, errorCode, message) = parse(minN, maxN);

        if(success)
        {
            n = data;
        }
        else
        {
            shouldRepeat = true;
            std::cerr << message << std::endl;
        }

    } while (shouldRepeat);
}

void GetVetor(std::vector<int> &numbers, int n, int minInt, int maxInt)
{
    std::cout << "Please enter " << Pluralize(n, "integer", "integers") <<", each in the range of [" << minInt <<", " << maxInt << "]:" << std::endl;
    int i = 0;

    do
    {
        int k;
        bool shouldRepeat = false;
        do
        {   
            shouldRepeat = false;
            std::cout << "The [" << i << "] interger: ";
            tie(success, data, errorCode, message) = parse(minInt, maxInt);
            if(success)
            {
                k = data;
            }
            else
            {
                shouldRepeat = true;
                std::cerr << message << std::endl;
            }
        } while (shouldRepeat);
        
        numbers.push_back(k);
        i++;
    } while (i < n);
    
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


void BuildDynamicArray(std::vector<int> &numbers, int &n)
{
    GetN(n, 5, 10);
    GetVetor(numbers, n, 1, 100);
    std::cout << "You have entered "<< Pluralize(n, "integer", "integers") << ": ";
    std::cout << numbers[0];
    for (int i = 1; i < numbers.size(); i++)
    {
        std::cout << ", "<< numbers[i];
    }
    std::cout << std::endl;
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



