#pragma once
#include <stdlib.h>
#include <time.h>
#include <memory>

class RandomIntegerGenerator
{
private:
    inline static std::shared_ptr<RandomIntegerGenerator> _instance = NULL;
    RandomIntegerGenerator()
    {   
        srand(time(NULL));
    };

public:
    static std::shared_ptr<RandomIntegerGenerator> GetInstance()
    {
        if(_instance == NULL)
        {
            _instance.reset(new RandomIntegerGenerator);
        }
        return _instance;
    }

    int next();
    int next(int left, int right);
    int next(int ceiling);
};
