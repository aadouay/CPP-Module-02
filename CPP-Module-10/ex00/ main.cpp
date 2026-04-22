#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>

int main(int ac, char **av){
    if(ac != 2){
        std::cerr << "Erorr : Impossible d'ouvrir le fichier" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange btc;
        btc.loadDatabase("data.csv");
        btc.processInput(av[1]);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}