#pragma once

#include <iostream>
#include "Base.hpp"

class A: public Base{
    public:
        void    print(){
            std::cout << "OBJ IS A" << std::endl;
        }
};