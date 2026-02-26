#include <iostream>
#include <ostream>

template<typename T, typename F>

void applique(T &value, F function){value = function(value);}
int add(int value){return value + value;}

int main() {
    int note = 25;
    applique(note, add);
    std::cout << note << std::endl;
    
}