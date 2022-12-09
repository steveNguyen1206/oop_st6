#pragma once
#include "Object.h"
#include <string>

class Integer : public Object {
private:
	int _value;
public:
	Integer();
	Integer(int);
	int value();
	std::string toString();
};