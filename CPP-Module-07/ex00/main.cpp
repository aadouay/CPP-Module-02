#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if(ac != 2){
        std::cerr << "Pls Enter tow args" << std::endl;
        std::cerr << "Example : ./convert 0" << std::endl;
        return 1;
    }
    // std::cout << "Input : " << av[1] << std::endl;
    ScalarConverter::convert(av[1]);
}