//
// Created by Данила Фомин on 26.12.2017.
//

#ifndef LAB3_GRAPH_HPP
#define LAB3_GRAPH_HPP

#include <map>
#include <ostream>
#include "GraphInterface.hpp"

namespace lab3 {
    class Graph : public GraphInterface {
    public:
        //constructors

        Graph(std::initializer_list<std::string> initList);

        Graph() = delete;

        Graph(const Graph&) = default;

        Graph(Graph&&) noexcept = default;

        //operators =

        Graph& operator=(const Graph&) = default;

        Graph& operator=(Graph&&) = default;

        //destructor

        ~Graph() override = default;

        //methods of GraphInterface

        bool degenerated() const noexcept override;

        std::string currentNode() const override;

        DistArray neighbourNodes() const override;

        void moveTo(const std::string&) override;

        //methods to configure

        void updateRelations(const std::string& node1, const std::string& node2, double dist);

        // methods to output

        void toDOT(std::ostream& stream, bool realSize) const;

    private:

        std::map<std::string, std::map<std::string, double> > _mapOfNodes;

        std::string _currentNode;

    };
}

#endif //LAB3_GRAPH_HPP
