#include "RandomIntegerGenerator.h"
#include "RandomPoinGenerator.h"
#include "Point.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>

struct {
    std::vector<Point> points;
}state;

std::shared_ptr<RandomIntegerGenerator> RandomIntegerGenerator::_my_instance;

int main()
{
    std::cout << "Point serialization" << std::endl;

    int n = RandomIntegerGenerator::instance()->next(5,10);
    RandomPointGenerator rpg;
    for(int i = 0; i < n; i++)
        state.points.push_back(rpg.next(1,100));

    std::ofstream writer;
    writer.open("points.txt", std::ios::out);
    writer << n << "\n";

    for(int i = 0; i < state.points.size(); i++)
        state.points[i].WritePoint(writer);

    writer.close();
}