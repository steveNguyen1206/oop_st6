#pragma once
#include <string>
#include <memory.h>
#include "dataset.h"

class DataContext
{
private:
    inline static std::shared_ptr<DataContext> _instance = NULL;
public:
    static std::shared_ptr<DataContext> GetInstance()
    {
        if(_instance == NULL)
        {
            _instance.reset(new DataContext());
        }
        return _instance;
    }
private:
    std::string _dbFolder = "";
    std::shared_ptr<ProductDataset> _products = NULL;
    DataContext();
public:
    std::shared_ptr<ProductDataset> Products();

public:

};

