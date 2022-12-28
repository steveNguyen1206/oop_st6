#include "dataContext.h"

DataContext::DataContext()
{
    _dbFolder = "Product";
    _products.reset(new ProductDataset(_dbFolder));
}

std::shared_ptr<ProductDataset> DataContext::Products()
{
    return _products;
}
