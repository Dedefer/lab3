//
// Created by Данила Фомин on 22.12.2017.
//

#include <iostream>
#include <cmath>
#include <fstream>
#include "graphs/GraphInterface.hpp"
#include "graphs/Graph.hpp"
#include "dijkstra's algorithm/DijkstraClass.hpp"

int main() {
    lab3::Graph a{"1", "2", "3", "4", "5", "6"};
    a.updateRelations("1", "2", 7);
    a.updateRelations("1", "3", 9);
    a.updateRelations("1", "6", 14);
    a.updateRelations("2", "3", 10);
    a.updateRelations("2", "4", 15);
    a.updateRelations("3", "4", 11);
    a.updateRelations("3", "6", 2);
    a.updateRelations("4", "5", 6);
    a.updateRelations("5", "6", 9);

    std::ofstream str{"dot.txt"};
    if (str) {
        a.toDOT(str, true);
    }

    lab3::DijkstraClass dis{&a, "1"};
    std::cout << dis.distanceToNode("1") << std::endl;
    std::cout << dis.distanceToNode("2") << std::endl;
    std::cout << dis.distanceToNode("3") << std::endl;
    std::cout << dis.distanceToNode("4") << std::endl;
    std::cout << dis.distanceToNode("5") << std::endl;
    std::cout << dis.distanceToNode("6") << std::endl;
    auto v = dis.pathToNode("5");
    for (auto [i1, i2] : v) {
        std::cout << i1 + "-" + i2 << std::endl;
    }
    return 0;
}