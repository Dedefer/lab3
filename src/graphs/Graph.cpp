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



void lab3::Graph::moveTo(const std::string& node) {
    auto checker = _mapOfNodes.find(node);
    if (checker != _mapOfNodes.end()) {
        _currentNode = node;
    } else {
        throw std::logic_error{"node is missing"};
    }
}

void lab3::Graph::updateRelations(const std::string& node1, const std::string& node2, double dist) {
    if (node1 != node2) {
        if (dist > 0) {
            auto pNode1 = _mapOfNodes.find(node1);
            auto pNode2 = _mapOfNodes.find(node2);
            auto null = _mapOfNodes.end();
            if ((pNode1 != null) && (pNode2 != null)) {
                pNode1->second[node2] = dist;
                pNode2->second[node1] = dist;
                return;
            }
            throw std::logic_error{"nodes are incorrect"};
        }
        throw std::logic_error{"distance must be greater then zero"};
    }
    throw std::logic_error{"can't create reflectional relation"};
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

void lab3::Graph::toDOT(std::ostream& stream, bool realSize) const {
    std::map<std::string, bool> visualized;
    stream << "graph graphname {\n";
    for (const auto& [node1, nodes2] : _mapOfNodes) {
        for (const auto& [node2, weight] : nodes2) {

            if (!visualized[node1 + node2] && !visualized[node2 + node1]) {
                stream << "\t" << node1 + " -- " + node2 << " [label="
                       << weight;
                if (realSize) { stream << " len=" << weight; }
                stream << "]" << std::endl;
                visualized[node1 + node2] = true;
            }
        }
    }
    stream << "}";
}
