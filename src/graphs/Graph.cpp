//
// Created by Данила Фомин on 26.12.2017.
//

#include "Graph.hpp"



bool lab3::Graph::degenerated() const noexcept {
    return _mapOfNodes.empty();
}

std::string lab3::Graph::currentNode() const {
    if (!_currentNode.empty()) {
        return _currentNode;
    }
    throw std::logic_error{"Graph is degenerated"};
}

lab3::GraphInterface::DistArray lab3::Graph::neighbourNodes() const {
    if (!_currentNode.empty()) {
        const auto& currentNodeMap = _mapOfNodes.at(_currentNode);
        DistArray resultArray;
        for (const auto& [nodeName, distance] : currentNodeMap) {
            resultArray.push_back(DistPair{nodeName, distance});
        }
        return std::move(resultArray);
    }
    throw std::logic_error{"Graph is degenerated"};
}



void lab3::Graph::moveTo(std::string node) {
    auto checker = _mapOfNodes.find(node);
    if (checker != _mapOfNodes.end()) {
        _currentNode = node;
    } else {
        throw std::logic_error{"node is missing"};
    }
}

void lab3::Graph::updateRelations(std::string node1, std::string node2, double dist) {
    if (dist > 0) {
        auto checker1 = _mapOfNodes.find(node1);
        auto checker2 = _mapOfNodes.find(node2);
        auto null = _mapOfNodes.end();
        if ((checker1 != null) && (checker2 != null)) {
            _mapOfNodes[node1][node2] = dist;
            _mapOfNodes[node2][node1] = dist;
            return;
        }
        throw std::logic_error{"nodes are incorrect"};
    }
    throw std::logic_error{"distance must be greater then zero"};
}

lab3::Graph::Graph(std::initializer_list<std::string> initList) {
    if (initList.size()) {
        for (auto &nodeName : initList) {
            auto checker = _mapOfNodes.find(nodeName);
            if (checker == _mapOfNodes.end()) {
                _mapOfNodes[nodeName];
            }
        }
        _currentNode = *initList.begin();
    }
}
