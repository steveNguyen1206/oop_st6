#include "ParserFactory.h"
#include "CircleParser.h"
#include "RectangleParser.h"
#include "SquareParser.h"
#include <iostream>
#include "Utils.h"
#include <vector>

int main() {
    std::vector<std::string> lines = {
        "Square a=12",
        "Circle r=12",
        "Square a=7",
        "Rectangle w=3, h=4",
        "Rectangle w=6, h=8",
        "Circle r=5",
        "Square a=8"
    };


    ParserFactory factory;
    factory.registerWith(new SquareParser());
    factory.registerWith(new RectangleParser());
    factory.registerWith(new CircleParser());
    std::vector<IShape*> shapes;


    for (std::string line : lines) {
        // Example: line = "Square a=12"
        std::vector<std::string> tokens = Utils::String::split(line, " ");
        IParsable* parser = factory.create(tokens[0]); // "Square"=> SquareParser
        IShape* shape = dynamic_cast<IShape*>(parser->parse(line.erase(0, tokens[0].length()))); // "a=12" => Square(_a = 12)
        shapes.push_back(shape);
    }

    for (IShape* shape : shapes) { // Polymorphism
        std::cout << shape->toString() << ": area="
            << shape->area() << ", perimeter="
            << shape->perimeter() << std::endl;
    }
}