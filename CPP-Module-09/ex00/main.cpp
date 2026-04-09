#include <iostream>
#include "easyfind.hpp"
#include <list>
int main(){

    std::vector <int> data;
    data.push_back(12);
    data.push_back(132);
    data.push_back(376);
    data.push_back(8);

    std::list<int> myList;
    myList.push_back(123);
    myList.push_back(23);
    myList.push_back(12);
    myList.push_back(11);
    myList.push_back(10);

    try
    {
        std::vector <int>::iterator it = easyfind(data, 132);
        std::cout << "Find : " << *it << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::list <int>::iterator it = easyfind(myList, 10);
        std::cout << "Find : " << *it << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
}