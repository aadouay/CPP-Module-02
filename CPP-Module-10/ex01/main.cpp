#include "RPN.hpp"

int main(int ac, char **av){

    if(ac != 2){
        std::cerr << "Erorr : entre deux arguments !" << std::endl;
        std::cerr << "example : \n ./RPN 8 9 * 9 - 9 - 9 - 4 - 1 +" << std::endl;
    }
    
    try
    {
        RPN ev;
        ev.calculate(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}