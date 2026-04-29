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
        stack.parse_input_and_sort(av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}