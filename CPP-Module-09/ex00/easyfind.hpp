#pragma once
#include <iostream>
#include <vector>

template<typename T>

typename T::iterator   easyfind(T& data, int value){

    for (typename T::iterator it = data.begin(); it != data.end() ; ++it){
        if(*it == value)
            return it;
    }
    throw std::runtime_error("Value not found");
}
