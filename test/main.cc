#include <iostream>

#include <DataStructures/Gentree.hh>

class Entity {
public:
    explicit Entity(int id) noexcept
        : m_Id{ id }
    {
        
    }

    auto GetId() const -> int {
        return m_Id;
    }


private:
    int m_Id{};
};

int main(int, char**) {
    using namespace Mikoto;

    std::cout << "GenTree Test\n";

    GenTree<Entity> entities{};

    entities.Insert(-1);
    entities.Insert(1);
    entities.Insert(2);
    entities.Insert(3);
    entities.Insert(4);
    entities.Insert(5);

    std::cout << "Printing all entities:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem.GetId() << std::endl; });

    std::cout << "\nPrinting all entities with Id greater than 3:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem.GetId() << std::endl; },
                [](auto& elem) { return elem.GetId() > 3; });

    std::cout << "Exiting program...\n";

    return 0;
}