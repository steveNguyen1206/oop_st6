#pragma once
#include "Object.h"
#include <string>

class Student : public Object
{
public:
	Student(std::string name, std::string phone, std::string address) 
	{
		_name = name;
		_phone = phone;
		_address = address;
	};
	
private:
	std::string _name;
	std::string _phone;
	std::string _address;

public:
	std::string getName()
	{
		return _name;
	}

	std::string getPhone()
	{
		return _phone;
	}

	std::string getAddress()
	{
		return _address;
	}

	std::string toString()
	{
		return "Student";
	}
};

