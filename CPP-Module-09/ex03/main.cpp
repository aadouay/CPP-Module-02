#include <iostream>
#include <stack>
#include <vector>
#include <deque>



/*
    1. Le concept d'Adaptateur
    Par défaut, si tu ne précises rien, std::stack utilise un std::deque (Double-Ended Queue).
    Mais tu pourrais lui dire d'utiliser un std::vector ou une std::list.

    C++ :
    std::stack<int> s1;                    // Utilise std::deque par défaut
    std::stack<int, std::vector<int>> s2;  // Utilise std::vector à la place
    std::stack<int, std::list<int>> s3;    // Utilise std::list à la place
*/
class stack_container : public std::stack<int>{
    public:
        typedef typename std::stack<int>::container_type::iterator iterator;
        iterator start(){return this->c.begin();}
        iterator end(){return this->c.end();}
};
int main(){

    // std::stack <int> stock;
    // stock.push(24);
    // stock.push(12);
    // stock.push(10);
    // stock.push(23);
    // stock.push(14);
    // stock.push(11);

    // while(!stock.empty()){
    //     std::cout << stock.top() << std::endl;
    //     stock.pop();
    // }

    // std::cout << "size of stock is : " << stock.size() << std::endl;
    stack_container stock;
    stock.push(12);
    stock.push(10);
    stock.push(14);
    stock.push(1);
    stock.push(19);

    for(stack_container::iterator it = stock.start(); it != stock.end(); ++it)
        std::cout << *it << std::endl;
}
