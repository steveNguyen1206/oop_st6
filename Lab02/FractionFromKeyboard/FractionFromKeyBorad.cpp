#include "FractionFromKeyBoard.h"
#include <iostream>


bool isInRange(int x, int left, int right)
{
    return (left <= x && right >= x);
}

std::tuple<bool, Fraction, int, std::string> KeyBoradFraction::parse(std::string buffer, int left, int right)
{
    bool _success = true;
    Fraction _data;
    int _errorCode = 0;
    std::string _message = "";

    if(buffer.empty())
    {
        _success = false;
        _errorCode = KeyBoradFraction::ParseErrorCode::EmptyInput;
        _message = "Input cannot be empty.";
    }
    else
    {
        std::string pattern = "\\d+\\/\\d+"; //regular expresstion for only fraction format 
        bool matched = std::regex_match(buffer, std::regex(pattern));
        if(!matched)
        {
            _success = false;
            _errorCode = KeyBoradFraction::ParseErrorCode::InvalidInputFormat;
            _message = "Invalid input format.";
        }
        else
        {
            std::string split = "/";
            int position = buffer.find(split);
            int numerator = stoi(buffer.substr(0, position));
            int denominator = stoi(buffer.substr(position + 1, buffer.length() - position - 1));

            if(denominator == 0)
            {
                _success = false;
                _errorCode = KeyBoradFraction::ParseErrorCode::ZeroDenominator;
                _message = "Denominator cannot be zero.";
            }
            else if(!isInRange(numerator, left, right) || !isInRange(denominator, left, right))
            {
                _success = false;
                _errorCode = KeyBoradFraction::ParseErrorCode::ValueNotInDomain;
                _message = "The numerator and denominator should be in the range of [" + std::to_string(left) + ", " + std::to_string(right) + "].";
            }
            else
            {
                _data = Fraction(numerator, denominator);
            }
        }
    }

    auto result = std::make_tuple(_success, _data, _errorCode, _message);
    return result;

}

void GetVector(std::vector<Fraction> &fractions, int n, int left, int right)
{
    int i = 0;
    do
    {
        bool shouldRepeat = false;
        bool success;
        Fraction data;
        int errorCode;
        std::string message;
        do
        {
            shouldRepeat = false;


            std::cout << "Fraction [" << i << "]" << ": ";
            std::string buffer;
            getline(std::cin, buffer);
            tie(success, data, errorCode, message) = KeyBoradFraction::parse(buffer, left, right);
            if(!success)
            {
                shouldRepeat = true;
                std::cerr << "Error: " << message << std::endl;
            }

        } while (shouldRepeat);

        fractions.push_back(data);

        i++;
    } while (i < n);
    
}
