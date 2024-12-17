#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <utility>

namespace Mikoto {

    template<typename T>
    class GenTree {
    public:
        using value_type = T; 
        using reference_type = T;

        template<typename... Args>
        auto Insert(Args&&... args) -> bool;

        template<typename UnaryPred, typename... Args>
        auto InsertChild(UnaryPred&& pred, auto&&... args) -> bool;

        template<typename UnaryPred>
        auto Erase(UnaryPred&& pred) -> bool;

        template<typename UnaryPred>
        auto Contains(UnaryPred&& pred) -> bool;

        template<typename UnaryPred>
        auto Get(UnaryPred&& pred) -> reference_type;

    private:
        struct Node {
            template<typename... Args>
            Node(Args&&... args) 
                :   data{ std::forward<Args>(args)... }
            {

            }

            value_type data;
            std::vector<std::unique_ptr<Node>> children;
        };
    
    private:
        std::vector<std::unique_ptr<Node>> m_Nodes{};
    };
}