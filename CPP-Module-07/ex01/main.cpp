#include "Serializer.hpp"

int main(){


    Data origin;
    origin.value = 1337;
    intptr_t raw;
    raw = Serializer::serialize(&origin);
    std::cout << raw << std::endl;
    Data* repl;
    repl = Serializer::deserialize(raw);
    std::cout << repl << std::endl;

    if (&origin == repl)
        std::cout << "Pointers are equal" << std::endl;
    else
        std::cout << "Pointers are NOT equal" << std::endl;

}