#ifndef _RANDOMLY_GENERATED_INTERGERS_H
#define _RANDOMLY_GENERATED_INTERGERS_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <math.h>
#include <tuple>

typedef bool (*Predicate) (int number);
bool isOdd(int);
bool isEven(int);
bool isPalindromic (int);
bool isPrime(int);


std::vector<int> Reduce(std::vector<int> numbers, Predicate sastify);
void GetVetor(std::vector<int> &numbers, int &n, int min_n, int max_n, int min_int, int max_int);
std::string Pluralize(int count, std::string singular, std::string plural);
void FindSubVector(std::vector<int> numbers, std::string condition, Predicate sastify);


#endif
