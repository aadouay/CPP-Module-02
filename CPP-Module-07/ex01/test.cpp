#include <iostream>
#include <cstdint>   // for uintptr_t

class A{
    int a;
    char b;
    public:
        A(): a(25), b('a'){}
        void pranti_ikhan(){
            std::cout << a << std::endl;
            std::cout << b << std::endl;
        }
};

class C{
    int a;
    char b;
    public:
        C(): a(65), b('J'){}
        void pranti_ikhan(){
            std::cout << a << std::endl;
            std::cout << b << std::endl;
        }
};

class B : public C, A{
    int a2;
    char b2;
    public:
        B(): a2(15), b2('b'){}
        void pranti_ikhan(){
            std::cout << a2 << std::endl;
            std::cout << b2 << std::endl;
        }
};

int main() {

    int b = 97;
    A *i = reinterpret_cast <A *> (&b);
    i->pranti_ikhan();
    // char *asscii = reinterpret_cast <char *> (&b);
    // std::cout << *asscii << std::endl;

    return 0;
}
