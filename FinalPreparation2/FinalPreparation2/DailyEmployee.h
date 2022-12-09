#pragma once
#include "Employee.h"
#include <string>

class DailyEmployee : public Employee
{
public:
	DailyEmployee(int, int);

private:
	int _dayCount;
	int _paymentPerDay;
public:
	std::string toString();
	int salary();
};

