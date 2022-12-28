#ifndef _INTEGER_H
#define _INTEGER_H
#include <iostream>
#include <stdlib.h> 
#include "time.h"
#include <memory>

//singleton to limit number of object created to one
class RandomIntegerGenerator
{
public:
    static std::shared_ptr<RandomIntegerGenerator> _my_instance;
private:
    RandomIntegerGenerator()
    {
        std::cout << "test";
        srand(time(NULL));
    }

public:
    static std::shared_ptr<RandomIntegerGenerator> instance()
    {
        if(_my_instance == NULL)
        {
            _my_instance.reset(new RandomIntegerGenerator);
        }
            return _my_instance;
    }

    int next();
    int next(int ceiling);
    int next(int left, int right);
};



// template <class T>
// class SmartPtr
// {

// }



#endif