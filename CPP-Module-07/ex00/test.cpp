#include <iostream>
#include <string>
#include <cctype>



class Animal {
    public:
        int a = 10;
        int b = 22;
};

class Dog : public Animal {
    public:
        int c = 54;
        int d = 2;
};

int main() {

    Animal *addr = new Dog; // upcast happing her hytach addr mn type animal not dog !
    std::cout << "befor downcast" << std::endl;
    std::cout << "a = " << addr->a << std::endl;

    Dog *down = static_cast<Dog*> (addr);
    std::cout << "after downcast" << std::endl;
    std::cout << "c = " << down->c << std::endl;
    return 0;
}