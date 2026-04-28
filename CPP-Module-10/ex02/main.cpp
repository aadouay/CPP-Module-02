#include <iostream>
#include <vector>
#include "PmergeMe.hpp"

int main(int ac, char **av){

    if(ac < 2){
        // std::cout << "ikhan" << std::endl;
        return 1;
    }
        
    try
    {
        PmergeMe stack;
        stack.parse_input(av);
        std::cout << "Avant : ";
        // std::cout << std::endl;
        stack.print_container_vec();
        // std::cout << std::endl;
        std::cout << "Apres : ";
        stack.sort_vec(stack.stock_vec);
        stack.print_container_vec();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}