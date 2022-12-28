#ifndef _INTERGERS_FROM_KEYBOARD_H
#define _INTERGERS_FROM_KEYBOARD_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <math.h>
#include <tuple>

enum IntergerParseErrorCode {
    EmptyInput,
    InvalidFormat,
    ValueNotInDomain
};

typedef bool (*Predicate) (int number);
bool isOdd(int);
bool isEven(int);
bool isPalindromic (int);
bool isPrime(int);


std::vector<int> Reduce(std::vector<int> numbers, Predicate sastify);

std::tuple<bool, int, int, std::string> parse(int minRange, int maxRange);
void GetN(int &n, int minN, int maxN);
void GetVetor(std::vector<int> &numbers, int n, int minInt, int maxInt);
std::string Pluralize(int count, std::string singular, std::string plural);
void BuildDynamicArray(std::vector<int> &number, int &n);

void FindSubVector(std::vector<int> numbers, std::string condition, Predicate sastify);


#endif
