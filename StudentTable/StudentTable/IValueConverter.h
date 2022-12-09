#pragma once
#include <memory>
#include "Object.h"
#include <string>

class IValueConverter : public Object
{
public:

private:
		
public:
	virtual std::string convert( std::shared_ptr<Object> object) = 0;
};

