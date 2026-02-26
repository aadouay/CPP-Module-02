#include <iostream>
#include "iter.hpp"

void multi(int &n){n = n * 2;}

void    remplir_stcok(int *array, int start_value, int size){
    for(int i = 0; i < size; i++){
        array[i] = start_value + i;
    }
}

int main(){
    int array[10];
    remplir_stcok(array, 20, 10);

    std::cout << "avant apliquer la function" << std::endl;
    std::cout << "|";
    for(int i = 0; i < 10; i++){
        std::cout << array[i] << " | ";
    }
    std::cout << std::endl;

    std::cout << "apres apliquer la function" << std::endl;
    iter(array, 10, multi);

    std::cout << "|";
    for(int i = 0; i < 10; i++){
        std::cout << array[i] << " | ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "tout est terminer !";
}