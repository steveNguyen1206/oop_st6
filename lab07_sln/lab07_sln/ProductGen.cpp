#include "ProductGen.h"
#include <memory>

Product ProductGenerator::next(std::string id)
{
    std::string name;
    int price;

    std::string manufact = SampleProduct::product_manufacts[RandomIntegerGenerator::GetInstance()->next(
        SampleProduct::product_manufacts.size()
    )];

    std::string brand = SampleProduct::product_brands[RandomIntegerGenerator::GetInstance()->next(
        SampleProduct::product_brands.size()
    )];

    std::string screenSize = SampleProduct::product_screensize[RandomIntegerGenerator::GetInstance()->next(
        SampleProduct::product_screensize.size()
    )];

    std::stringstream builder;
    builder << brand << " " << manufact << " " << screenSize;
    name = builder.str();

    price = SampleProduct::product_prices[RandomIntegerGenerator::GetInstance()->next(
        SampleProduct::product_prices.size()
    )];

    Product p(name, price, id);
    return p;
}
