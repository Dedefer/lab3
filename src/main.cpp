//
// Created by Данила Фомин on 22.12.2017.
//

#include <iostream>
#include <cmath>
#include "graphs/GraphInterface.hpp"
#include "graphs/Graph.hpp"

int main() {
    lab3::Graph a{"1", "2", "3"};
    std::cout << a.currentNode() << std::endl;
    a.updateRelations("1", "2", 6);
    //a.updateRelations("2", "51", 1);

    a.moveTo("2");

    auto c = std::move(a);
    auto b = c.neighbourNodes();
    for (auto i : b) {
        std::cout << i.first << " " << i.second << std::endl;
    }
    return 0;
}