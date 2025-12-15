#include "ScalarConverter.hpp"

int main(int ac, char **av){
    if(ac != 2){
        std::cerr << "Pls Enter tow args" << std::endl;
        std::cerr << "Example : ./convert 0" << std::endl;
        return 1;
    }
    // std::cout << "Input : " << std::numeric_limits<double>::max() << std::endl;
    ScalarConverter::convert(av[1]);
    // float num = std::strtod("4263", NULL);

    // if(std::strtod(av[1], NULL) - static_cast<int>(std::strtod(av[1], NULL)) == 0.0f){
    //     std::cout << "Converted value: " << std::strtod(av[1], NULL);
    //     std::cout << ".0f" << std::endl;
    // }
    // else{
    //     std::cout << "Converted value: " << std::strtod(av[1], NULL) << "f" << std::endl;
    // }
    
    return 0;
}