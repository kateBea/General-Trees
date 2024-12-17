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
        auto Insert(Args&&... args) -> bool {
            auto result{ std::make_unique<Node>(std::forward<Args>(args)...) };

            if (result) {
                m_Nodes.emplace_back(std::move(result));
                return true;
            }

            return false;
        }

        template<typename UnaryPred, typename... Args>
        auto InsertChild(UnaryPred&& pred, auto&&... args) -> bool;

        template<typename UnaryPred>
        auto Erase(UnaryPred&& pred) -> bool;

        template<typename UnaryPred>
        auto Contains(UnaryPred&& pred) -> bool;

        template<typename UnaryPred>
        auto Get(UnaryPred&& pred) -> reference_type;

        template<typename UnaryFunc>
        auto ForAll(UnaryFunc&& func) -> void {

            for (auto& node : m_Nodes) {
                Traverse(func, *node);
            }
        }

        template<typename UnaryFunc, typename UnaryPred>
        auto ForAll(UnaryFunc&& func, UnaryPred&& pred) -> void {
            for (auto& node : m_Nodes) {
                TraverseWithPred(func, pred, *node);
            }
        }

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

        template<typename UnaryFunc>
        auto Traverse(UnaryFunc&& func, Node& node) -> void {
            func(node.data);

            for (auto& child : node.children) {
                Traverse(func, *child);
            }
        }

        template<typename UnaryFunc, typename UnaryPred>
        auto TraverseWithPred(UnaryFunc&& func, UnaryPred&& pred, Node& node) -> void {
            if (pred(node.data)) {
                func(node.data);
            }

            for (auto& child : node.children) {
                Traverse(func, *child);
            }
        }

    
    private:
        std::vector<std::unique_ptr<Node>> m_Nodes{};
    };
}