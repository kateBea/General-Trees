# 🌳 General Tree Implementation in Modern C++

A lightweight and flexible **General Tree** implementation written in **C++17** and above, designed for use in scenarios requiring hierarchical structures. This implementation tries emphasizes safety, modularity, and extensibility using modern C++ features like `std::unique_ptr`.


## 🚀 Features

- **General Tree Support**:
  - A tree with multiple root nodes and nodes with arbitrary children.
  - Each node owns its children using `std::unique_ptr`, ensuring memory safety.

- **Custom Insertion**:
  - Insert a node under an existing parent node.
  - If the parent node doesn't exist, the new node is automatically added to the first level as a root.

- **Erasure Methods**:
  - Delete nodes by that meet a certain criteria, including roots or deeper children.

- **Query Methods**:
  - Check if a specific value exists in the tree.

- **Traversal Support**:
  - Depth-first traversal with customizable callback functions.


## 💻 Code Structure

The implementation consists of two main components:

1. **`GeneralTreeNode`**: Represents a single node in the tree.
    - Holds data of type `T`.
    - Owns children nodes via `std::unique_ptr`.

2. **`GeneralTree`**: Represents the tree structure.
    - Manages root nodes and provides operations like Insert, Erase and Traversal.


## 📚 API Overview

### General Tree Node

```cpp
template <typename T>
struct Node {
    value_type data;

    std::vector<
        std::unique_ptr<GeneralTreeNode<T>>
    > children;
};
```

### GeneralTree

```cpp
template <typename T>
class GeneralTree {
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
};
```


## 🛠️ Usage Example

Here’s how you can use the general tree in your project:

```cpp
#include <iostream>
#include <DataStructures/Gentree.hh>

int main(int, char**) {
    using namespace Mikoto;

    std::cout << "GenTree Test\n";

    GenTree<int> entities{};

    entities.Insert(-1);
    entities.Insert(1);
    entities.Insert(2);
    entities.Insert(3);
    entities.Insert(4);
    entities.Insert(5);

    std::cout << "Printing all entities:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem << std::endl; });

    std::cout << "\nPrinting all entities with Id greater than 3:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem.GetId() << std::endl; },
                [](auto& elem) { return elem > 3; });

    std::cout << "Exiting program...\n";

    return 0;
}
```


## ✅ Output Example

```
Printing all entities:
Root: -1
Root: 1
Root: 2
Root: 3
Root: 4
Root: 5

Printing all entities with Id greater than 3:
Root: 4
Root: 5
Exiting program...
```


## 🛠 Requirements

- A **C++17** standard compliant compiler (e.g., GCC, Clang, MSVC).
- Cmake installed to build the test from ``CMakeLists.txt`` file (optional).


## 🎯 Use Cases

- File system representation 🗂️.
- Scene graph hierarchies in game engines 🎮.
- Generic tree-based structures in applications.


## 📄 License

This project is licensed under the [**MIT License**](LICENSE).
