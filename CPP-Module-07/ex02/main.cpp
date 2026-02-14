#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib> 
#include <ctime>

Base * generate(void){
    int rdm = (rand() % 3);
    if(rdm == 0) return new A;
    if(rdm == 1) return new B;
    return new C;
}

void identify(Base* p){
    if(dynamic_cast <A*> (p) != nullptr)
        std::cout << "This object is come from Class A" << std::endl;
        
    else if (dynamic_cast <B*> (p) != nullptr)
        std::cout << "This object is come from Class B" << std::endl;
        
    else if(dynamic_cast <C*> (p) != nullptr)
        std::cout << "This object is come from Class C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
void identify(Base& p){

    try
    {
        A& add = dynamic_cast <A&> (p);
        (void)add;
        std::cout << "This object is come from Class A" << std::endl;
        return ;
    }
    catch(const std::bad_cast&){}

    try
    {
        B& add = dynamic_cast <B&> (p);
        (void)add;
        std::cout << "This object is come from Class B" << std::endl;
        return ;
    }
    catch(const std::bad_cast&){}

    try
    {
        C& add = dynamic_cast <C&> (p);
        (void)add;
        std::cout << "This object is come from Class C" << std::endl;
        return ;
    }
    catch(const std::bad_cast&){
        std::cout << "Unknown type" << std::endl;
    }
}

int main(){
    std::srand(std::time(NULL));

    {
        Base *add = generate();
        identify(add);
        delete add;
    }
    
    {
        Base *add = generate();
        identify(*add);
        delete add;
    }
}