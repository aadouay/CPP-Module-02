#pragma once

#include <iostream>
#include <Base.hpp>

class C: public Base{
    public:
        void    print(){
            std::cout << "OBJ IS C" << std::endl;
        }
};