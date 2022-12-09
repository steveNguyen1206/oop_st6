#pragma once
#include "Object.h"
#include "Student.h"
#include "IValueConverter.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>

class Table : public Object
{
public:
	Table(std::vector<std::string> headers, 
		std::vector<int> widths, 
		std::vector<std::shared_ptr<Object>> data, 
		std::shared_ptr<IValueConverter> converter) 
	{
		_headers = headers;
		_widths = widths;
		_data = data;
		_converter = converter;
	};

private:
	std::vector<std::string> _headers;
	std::vector<int> _widths;
	std::vector<std::shared_ptr<Object>> _data;
	std::shared_ptr<IValueConverter> _converter;

public:
	void display()
	{
		std::cout << std::right << std::setw(_widths[0]) << _headers[0] << "|"
			<< std::right << std::setw(_widths[1]) << _headers[1] << "|"
			<< std::right << std::setw(_widths[2]) << _headers[2] << "|" << std::endl;

		int length = 0;
		for (auto i : _widths)
			length += i;
		length += 3;
		std::cout << std::setw(length) << std::setfill('-') << "-" << std::endl;
		for (std::shared_ptr<Object> i : _data)
		{
			std::cout << _converter->convert(i);
		}
		std::cout << std::setw(length) << std::setfill('-') << "-" << std::endl;
	};

	std::string toString()
	{
		return "Table";
	}
};

