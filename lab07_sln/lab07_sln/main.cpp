#include "dataContext.h"
#include "dataset.h"
#include "product.h"
#include "ProductGen.h"
#include "ProductIdGen.h"
#include "RandomIntegerGenerator.h"
#include "Utils.h"
#include <string>
#include <vector>

int main()
{
    int n = RandomIntegerGenerator::GetInstance()->next(5, 10);
    auto context = DataContext::GetInstance(); 

    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::string id = context->Products()->idGen()->next();
        std::cout << id << std::endl;
        ProductGenerator ProductGen;
        Product p = ProductGen.next(id);
        context->Products()->add(p);
    }

    std::vector<Product> products;
    products = context->Products()->getAll();
    for (auto p : products)
    {
        std::cout << p.toString() << std::endl;
    }
}