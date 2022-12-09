#pragma once
#include "Object.h"
#include "IParsable.h"
#include <string>
#include <map>


class ParserFactory : public Object
{
public:

private:
	std::map<std::string, IParsable*> _container;
public: 
	void registerWith(IParsable* parser);
	IParsable* create(std::string type);
	std::string toString();
};

