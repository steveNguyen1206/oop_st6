#pragma once
#include "Employee.h"
#include <string>

class Manager : public Employee
{
public:
	Manager(int, int, int);

private:
	int _employeeCount;
	int _paymentPerEmployee;
	int _baseSalary();
public:
	std::string toString();
	int salary();
};

