#pragma once
#include "Student.h"
#include "IValueConverter.h"
#include <memory>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>

class StudentToRowConverter : public IValueConverter
{
public:
	StudentToRowConverter(std::vector<int> widths)
	{
		_widths = widths;
	};

private:
	std::vector<int> _widths;

public:
	std::string convert(std::shared_ptr<Object> object)
	{
		auto student = std::dynamic_pointer_cast<Student> (object);
		std::stringstream builder;
		builder << std::right << std::setw(_widths[0]) << student->getName() << "|"
			<< std::right << std::setw(_widths[1]) << student->getPhone() << "|"
			<< std::right << std::setw(_widths[2]) << student->getAddress() << "|" << std::endl;
		
		std::string res = builder.str();
		return res;
	};

	std::string toString()
	{
		return "Student to row converter";
	}
};

