#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib> 
#include <ctime>


// generate object !

Base * generate(void){
    Base *obj;
    switch (rand() % 3)
    {
        case 0:
            obj = new A;
            break;
        case 1:
            obj = new B;
            break;
        case 2:
            obj = new C;
    }
    return obj;
}

int main(){
    std::srand(std::time(NULL));

    Base *add = generate();
    A *type = dynamic_cast<A *> (add);
    B *type2 = dynamic_cast<B *> (add);
    C *type3 = dynamic_cast<C *> (add);
    if(type != nullptr){
        std::cout << "the onject is A" << std::endl;
    }
    if(type2 != nullptr){
        std::cout << "the onject is B" << std::endl;
    }
    if(type3 != nullptr){
        std::cout << "the onject is C" << std::endl;
    }
}