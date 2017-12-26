//
// Created by Данила Фомин on 22.12.2017.
//

#ifndef LAB3_GRAPHINTERFACE_HPP
#define LAB3_GRAPHINTERFACE_HPP

#include <string>
#include <vector>
#include "../lab3_namespace.hpp"

namespace lab3 {
    class GraphInterface {
    public:

        using DistPair = std::pair<std::string, double>;

        using DistArray = std::vector<DistPair>;

        virtual bool degenerated() const noexcept = 0;

        virtual void moveTo(std::string node) = 0;

        virtual std::string currentNode() const = 0;

        virtual DistArray neighbourNodes() const = 0;

        virtual ~GraphInterface() = default;
    };
}


#endif //LAB3_GRAPHINTERFACE_HPP
