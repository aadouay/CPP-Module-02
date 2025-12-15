#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if(ac != 2){
        std::cerr << "Pls Enter tow args" << std::endl;
        std::cerr << "Example : ./convert 0" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}