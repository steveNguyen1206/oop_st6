#include "DailyEmployee.h"

DailyEmployee::DailyEmployee(int dayCount, int paymentPerDay)
{
	_dayCount = dayCount;
	_paymentPerDay = paymentPerDay;
}
std::string DailyEmployee::toString()
{
	return "Daily emloyee";
}

int DailyEmployee::salary()
{
	int salary = _dayCount* _paymentPerDay;
	return salary;
}
