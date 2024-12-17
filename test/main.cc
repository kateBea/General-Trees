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

    std::cout << "\nInterting childs for 5:\n";

    entities.InsertChild([](const auto& elem) { return elem.GetId() == 5; }, -11);
    entities.InsertChild([](const auto& elem) { return elem.GetId() == 5; }, 12);
    entities.InsertChild([](const auto& elem) { return elem.GetId() == 5; }, 23);
    entities.InsertChild([](const auto& elem) { return elem.GetId() == 5; }, 34);
    entities.InsertChild([](const auto& elem) { return elem.GetId() == 5; }, 45);
    entities.InsertChild([](const auto& elem) { return elem.GetId() == 5; }, 56);

    std::cout << "Printing all entities:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem.GetId() << std::endl; });

    std::cout << "\nPrinting all entities with Id equal to 5:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem.GetId() << std::endl; },
                [](auto& elem) { return elem.GetId() == 5; });

    std::cout << "\nPrinting all entities with Id even:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem.GetId() << std::endl; },
                [](auto& elem) { return elem.GetId() % 2 == 0; });

    std::cout << "\nPrinting all entities with Id odd:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem.GetId() << std::endl; },
                [](auto& elem) { return elem.GetId() % 2 != 0; });

    std::cout << "\nGetting first element greather than 50\n";
    auto ref{ entities.Get([](auto& elem) { return elem.GetId() > 50; }) };
    std::cout << "Result: " << ref.GetId() << std::endl;

    std::cout << "\nErasing 5 and all of its children\n";
    entities.Erase([](auto& elem) { return elem.GetId() == 5; });

    std::cout << "Printing all entities:\n";
    entities.ForAll([](auto& elem) { std::cout << "Root: " << elem.GetId() << std::endl; });


    std::cout << "Exiting program...\n";

    return 0;
}