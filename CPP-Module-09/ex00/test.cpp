#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <list>



int main() {
    std::list<int> s;
    s.push_back(25);
    s.push_back(10);
    s.push_back(15);
    s.push_back(19);


    for(std::list<int>::iterator it = s.begin(); it != s.end(); ++it){
        if(*it == 15)
            std::cout << "find it : " << *it << std::endl;
    }
    std::deque<int> a;
    a.push_back(25);
    a.push_back(10);
    a.push_back(15);
    a.push_back(19);

    std::cout << "dans un deque on put trouve les element via index : " << a[2] << std::endl;
}