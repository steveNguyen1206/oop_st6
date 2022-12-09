#include "Integer.h"
#include "IntegerToCurrencyConverter.h"
#include "sstream"
#include "iostream"
#include "ParserFactory.h"
#include "DailyEmployeeParser.h"
#include <vector>
#include <string>



int main()
{
    ParserFactory factory;
    factory.registerWith(new DailyEmployeeParser());
    //factory.registerWith(new ProductEmployeeParser());
    //factory.registerWith(new ManagerParser());

    std::vector<std::string> lines = {
        //"ProductEmployee productCount=790, paymentPerProduct=20000",
        "DailyEmployee dayCount=20, paymentPerPay=1000000",
        //"ProductEmployee productCount=810, paymentPerProduct=19000",
        //"ProductEmployee productCount=900, paymentPerProduct=18000",
        //"Manager employeeCount=49, paymentPerEmployee=500000, baseSalary=6000000",
        "DailyEmployee dayCount=22, paymentPerPay=1100000",
        //"Manager employeeCount=37, paymentPerEmployee=500000, baseSalary=7000000",
        "DailyEmployee dayCount=18, paymentPerPay=1500000",
        //"Manager employeeCount=30, paymentPerEmployee=500000, baseSalary=5000000"
    };

    std::vector<Employee*> employees;

    for (std::string line : lines) {// "ProductEmployee productCount=790, paymentPerProduct=20000"
        int splitPosition = line.find_first_of(" ");
        std::string type = line.substr(0, splitPosition); // type = "ProductEmployee" 
        IParsable* parser = factory.create(type);

        // data = "productCount=790, paymentPerProduct=20000",
        std::string data = line.substr(splitPosition + 1, line.length() - splitPosition - 1);
        Employee* employee = dynamic_cast<Employee*>(parser->parse(data));
        employees.push_back(employee);
    }


    std::stringstream builder;
    IntegerToCurrencyConverter converter;
    

    for (auto employee : employees) {
        int salary = employee->salary();
        Object* i = new Integer(salary);
        std::string salaryInCurrency = converter.convert(i);
        std::cout << employee->toString() << ", salary:" << salaryInCurrency << std::endl;
        delete i;
    }
}