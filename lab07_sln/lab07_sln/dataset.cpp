#include "dataset.h"
#include <filesystem>

ProductDataset::ProductDataset()
{
}

ProductDataset::ProductDataset(std::string folder)
{
    _dbFolder = folder;
    _idGen.reset(new ProductIdGenerator(_dbFolder));
}

std::shared_ptr<ProductIdGenerator> ProductDataset::idGen()
{
    return _idGen;
}

int ProductDataset::add(const Product&p)
{
    if(!std::filesystem::exists(_dbFolder))
    {
        std::filesystem::create_directory(_dbFolder);
    }

    std::stringstream builder;
    builder << _dbFolder << "\\" << p.id() << ".txt";
    std::string filename = builder.str();

    std::ofstream writer(filename, std::ios::out);
    writer << p.toString();
    writer.close();
    return 1;
}

std::vector<Product> ProductDataset::getAll()
{
    std::vector<Product> result;
    for (const auto& file : std::filesystem::directory_iterator(_dbFolder))
    {
        std::stringstream builder;
        builder << _dbFolder << "\\" << file.path().filename().string();
        std::string filename = builder.str();

        std::ifstream reader(filename, std::ios::in);
        std::string buffer = "";
        std::getline(reader, buffer);
        reader.close();
        Product p = ProductDataset::parse(buffer);
        result.push_back(p);
    }
    return result;
}
Product ProductDataset::parse(std::string data)
{
    std::string separator = ", ";
    auto tokens = Utils::String::split(data, separator);

    separator = "=";
    std::string id;
    id = Utils::String::split(tokens[0], separator)[1];

    std::string name;
    name = Utils::String::split(tokens[1], separator)[1];

    int price = std::stoi(Utils::String::split(tokens[2], separator)[1]);

    Product p(name, price, id);
    return p;
}

