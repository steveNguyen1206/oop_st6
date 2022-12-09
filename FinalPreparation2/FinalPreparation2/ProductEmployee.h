#pragma once
#include "Employee.h"
#include <string>

class ProductEmplyee : public Employee
{
public:
	ProductEmplyee(int, int);

private:
	int _productCount;
	int _paymentPerProduct;
public:
	std::string toString();
	int salary();
};

