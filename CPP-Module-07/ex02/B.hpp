#pragma once

#include <iostream>
#include "Base.hpp"

class B: public Base{
    public:
        void    print(){
            std::cout << "OBJ IS B" << std::endl;
        }
};