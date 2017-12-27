//
// Created by Данила Фомин on 27.12.2017.
//

#ifndef LAB3_DIJKSTRACLASS_HPP
#define LAB3_DIJKSTRACLASS_HPP

#include <map>
#include "../graphs/GraphInterface.hpp"

namespace lab3 {
    class DijkstraClass {
    public:
        // types

        using Edge = std::pair<std::string, std::string>;

        using Path = std::vector<Edge>;

        // constructors

        DijkstraClass(GraphInterface* graph, const std::string& startNode);

        DijkstraClass() = delete;

        DijkstraClass(const DijkstraClass&) = delete;

        DijkstraClass(DijkstraClass&&) noexcept = delete;

        // operators =

        DijkstraClass& operator=(const DijkstraClass&) = delete;

        DijkstraClass& operator=(DijkstraClass&&) = delete;

        // destructor

        ~DijkstraClass() = default;

        // methods

        double distanceToNode(const std::string& destNode) const;

        Path pathToNode(const std::string& destNode) const;

    private:

        // fields

        std::map<std::string, std::pair<double, Path> > _mapOfPaths;

    };
}

#endif //LAB3_DIJKSTRACLASS_HPP
