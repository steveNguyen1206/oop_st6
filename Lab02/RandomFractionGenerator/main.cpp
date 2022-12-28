#include <iostream>
#include "Pluralize.h"
#include "Integer.h"
#include "Fraction.h"
#include "RandomFractionGenerator.h"
#include "RandomIntegerGenerator.h"
#include "Converters.h"
#include <vector>

/*
    Khi sử dụng SmartPointer để khai báo Singleton trong class RandomIntergerGenerator,
    vấn đề gặp phải là phần tử Fraction đầu tiên được lưa vào vector sẽ bị thay đổi giá trị sau khi tiếp tục random ra những Fraction tiếp theo

    Các trường hợp chạy thử và bị lỗi:
    -Sử dụng SmartPointer để cài Singleton, lưu Fraction random vào vector

    Các trường hợp chạy thử không bị lỗi (các phần tử Fraction không bị thay đổi giá trị):
    -Sử dụng mảng tĩnh Fraction[10] thay cho vector
    -Sử dụng RandomIntegerGenerator * thay cho SmartPointer khi định nghĩa Singleton cho class RandomIntegerGenerator: sẽ không bị lỗi khi lưu Fraction vào vector, nhưng bị memory leak vì con trỏ không tự hủy



*/

struct{
    std::vector <Fraction> fractions;
}state;

std::shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::_my_instance;

int main()
{
    std::cout << "Random fraction generator" << std::endl << std::endl;
    int n;
    n = RandomIntegerGenerator::instance()->next(5, 10);
    RandomFractionGenerator rfg;

    for (int i = 0; i < n; i++)
    {
        state.fractions.push_back(rfg.next(10, 100));

    }
    FractionToLowestTermConverter flc;
    FractionToStringConverter fsc;
    FractionToDecimalConverter fdc;
    FractionToPercentageConverter fpc;

    std::cout << "Generating " << Pluralize(n, "fraction: ", "fractions: ");
    std::cout << fsc.convert(state.fractions[0]);
    for (int i = 1; i < state.fractions.size(); i++)
    {
       std::cout << ", " << fsc.convert(state.fractions[i]);
    }


    std::cout << "\n" << Pluralize(n, "Fraction in their ", "Fractions in its ") << "lowest term: ";
    std::cout << flc.convert(state.fractions[0]);
    for(int i = 1; i < state.fractions.size(); i++)
    {
        std::cout << ", " << flc.convert(state.fractions[i]);
    }


    std::cout << "\n" << Pluralize(n, "Fraction in their ", "Fractions in its ") << "decimal form: ";
    std::cout << fdc.convert(state.fractions[0]);
    for(int i = 1; i < state.fractions.size(); i++)
    {
        std::cout << ", " << fdc.convert(state.fractions[i]);
    }


    std::cout << "\n" << Pluralize(n, "Fraction in their ", "Fractions in its ") << "percentage form: ";
    std::cout << fpc.convert(state.fractions[0]);
    for(int i = 1; i < state.fractions.size(); i++)
    {
        std::cout << ", " << fpc.convert(state.fractions[i]);
    }
}