//
// Created by Данила Фомин on 27.12.2017.
//

#include <cmath>
#include <queue>
#include "DijkstraClass.hpp"

lab3::DijkstraClass::DijkstraClass(lab3::GraphInterface* graph, const std::string& startNode) {
    // create map nodes to bool
    std::map<std::string, bool> nodeChecked;

    // init start node with 0
    _mapOfPaths[startNode] = {0, {}};

    // creating queue to check and pushing start node to it
    std::queue<std::string> nodesToCheck;
    nodesToCheck.push(startNode);

    // cycle while queue isn't empty
    while (!nodesToCheck.empty()) {
        // extracting first in queue node
        auto currentNode = nodesToCheck.front();
        nodesToCheck.pop();

        // if current node isn't in our map, then creating it
        // and init with infinity
        if (_mapOfPaths.find(currentNode) == _mapOfPaths.end()) {
            _mapOfPaths[currentNode] = {HUGE_VAL, {}};
        }

        // get access to current node for optimisation
        auto& currentNodeP = _mapOfPaths.at(currentNode);

        // moving to extracted node and getting it's neighbours
        graph->moveTo(currentNode);
        auto reachableNodes = graph->neighbourNodes();


        // for each neighbour doing
        for (const auto& [neighbourNode, weight] : reachableNodes) {
            // if neighbour is not checked yet
            if (!nodeChecked[neighbourNode]) {
                // if current neighbour isn't in our map, then creating it
                // and init with infinity
                if (_mapOfPaths.find(neighbourNode) == _mapOfPaths.end()) {
                    _mapOfPaths[neighbourNode] = {HUGE_VAL, {}};
                }
                // adding neighbour to queue
                nodesToCheck.push(neighbourNode);
                // if current path to neighbour greater then path to extracted node + weight
                // replacing path to it with path to extracted node + edge from extracted to neighbour
                auto& pathToNeighbourP = _mapOfPaths.at(neighbourNode);
                if (pathToNeighbourP.first > (currentNodeP.first + weight)) {
                    pathToNeighbourP.first = currentNodeP.first + weight;
                    pathToNeighbourP.second = currentNodeP.second;
                    pathToNeighbourP.second.push_back(Edge{currentNode, neighbourNode});
                }
            }
        }
        // checking current node
        nodeChecked[currentNode] = true;
    }
}

double lab3::DijkstraClass::distanceToNode(const std::string& destNode) const {
    auto pathPair = _mapOfPaths.find(destNode);
    if (pathPair != _mapOfPaths.end()) { return pathPair->second.first; }
    throw std::logic_error{"node is unreachable"};
}

lab3::DijkstraClass::Path lab3::DijkstraClass::pathToNode(const std::string& destNode) const {
    auto pathPair = _mapOfPaths.find(destNode);
    if (pathPair != _mapOfPaths.end()) { return pathPair->second.second; }
    throw std::logic_error{"node is unreachable"};
}
