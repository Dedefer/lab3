//
// Created by Данила Фомин on 26.12.2017.
//

#ifndef LAB3_GRAPH_HPP
#define LAB3_GRAPH_HPP

#include <map>
#include "GraphInterface.hpp"

namespace lab3 {
    class Graph : public GraphInterface {
    public:
        //constructors

        Graph(std::initializer_list<std::string> initList);

        Graph() = default;

        Graph(const Graph& obj) = default;

        Graph(Graph&& obj) noexcept = default;

        //operators =

        Graph& operator=(const Graph&) = default;

        Graph& operator=(Graph&&) = default;

        //destructor

        ~Graph() override = default;

        //methods of GraphInterface

        bool degenerated() const noexcept override;

        std::string currentNode() const override;

        DistArray neighbourNodes() const override;

        void moveTo(std::string) override;

        //methods to configure

        void updateRelations(std::string node1, std::string node2, double dist);

    private:

        std::map<std::string, std::map<std::string, double> > _mapOfNodes;

        std::string _currentNode;

    };
}

#endif //LAB3_GRAPH_HPP
